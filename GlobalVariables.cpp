#include "GlobalVariables.h"
#include <filesystem>
#include <fstream>
#include <iomanip>  // std::setwのために追加

using namespace std;

void GlobalVariables::SaveFile(const std::string& groupName) {
    // グループ名でデータを探す 
    auto itGroup = datas_.find(groupName);
    assert(itGroup != datas_.end() && "指定されたグループが見つかりません");

    json root; // グループの名前で空の JSON オブジェクトを作成 
    root[groupName] = json::object();

    // グループ内のアイテムを処理 
    for (auto& [itemName, item] : itGroup->second.items) {
        if (std::holds_alternative<int32_t>(item.value)) {
            // int32_t 型の値を追加 
            root[groupName][itemName] = std::get<int32_t>(item.value);
        } else if (std::holds_alternative<float>(item.value)) {
            // float_t 型の値を追加 
            root[groupName][itemName] = std::get<float>(item.value);
        } else if (std::holds_alternative<Vector3>(item.value)) {
            Vector3& value = std::get<Vector3>(item.value);
            root[groupName][itemName] = json::array({ value.x, value.y, value.z });
        } else if (std::holds_alternative<Vector2>(item.value)) {
            Vector2& value = std::get<Vector2>(item.value);
            root[groupName][itemName] = json::array({ value.x, value.y });
        }
    }

    // ディレクトリの存在を確認し、存在しない場合は作成 
    std::filesystem::path dir(kDirectoryPath);
    dir /= groupName;  // groupNameのディレクトリを作成
    if (!std::filesystem::exists(dir)) {
        std::filesystem::create_directory(dir);
    }

    // ファイルパスを作成
    std::string filePath = kDirectoryPath + groupName + "/" + groupName + ".json";

    // ファイルを書き込むために開く 
    std::ofstream ofs(filePath);
    if (!ofs.is_open()) {
        cerr << "データファイルのオープンに失敗しました: " << filePath << endl;
        return;
    }
    // JSON データを書き込む 
    ofs << std::setw(4) << root << std::endl;

    // デバッグ用のログを出力
    Novice::ScreenPrintf(500,0,"JSON Output:\n%s\n", root.dump(4).c_str());
}

void GlobalVariables::LoadFile(const std::string& groupName) {
    // ファイルパスを作成
    std::string filePath = kDirectoryPath + groupName + "/" + groupName + ".json";

    // ファイルが存在するか確認
    if (!std::filesystem::exists(filePath)) {
        printf("File not found: %s\n", filePath.c_str());
        return;
    }

    // ファイルを読み込む
    std::ifstream ifs(filePath);
    if (!ifs.is_open()) {
        printf("Failed to open file: %s\n", filePath.c_str());
        return;
    }

    // JSON データをパース
    json root;
    ifs >> root;

    // データを復元
    auto itGroup = root.find(groupName);
    if (itGroup != root.end()) {
        Group group;

        for (auto& [itemName, itemValue] : itGroup->items()) {
            if (itemValue.is_number_integer()) {
                group.items[itemName] = Item(itemValue.get<int32_t>());
            } else if (itemValue.is_number_float()) {
                group.items[itemName] = Item(itemValue.get<float>());
            } else if (itemValue.is_array()) {
                if (itemValue.size() == 2) {
                    Vector2 v = { itemValue[0].get<float>(), itemValue[1].get<float>() };
                    group.items[itemName] = Item(v);
                } else if (itemValue.size() == 3) {
                    Vector3 v = { itemValue[0].get<float>(), itemValue[1].get<float>(), itemValue[2].get<float>() };
                    group.items[itemName] = Item(v);
                }
            }
        }

        // データをマップに保存
        datas_[groupName] = group;
        printf("Data loaded successfully from %s\n", filePath.c_str());
    } else {
        printf("Group not found in JSON file: %s\n", groupName.c_str());
    }
}

