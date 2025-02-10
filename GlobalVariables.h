#pragma once
#include <Novice.h>
#include <Vector2.h>
#include <json.hpp>
#include <imgui.h>
#include <cassert>
#include <string>
#include <variant>
#include <map>
#include <array>
#include <Vector3.h> // Vector3.hの確認
#include <WinUser.h> // WinUser.hの確認
#include <iostream>
#include <filesystem>
#include <fstream>

// JSONライブラリのエイリアス
using json = nlohmann::json;

// Vector2.h の後に追加する

// Vector2 用の JSON 変換関数
inline void to_json(nlohmann::json& j, const Vector2& v) {
    j = nlohmann::json{ {"x", v.x}, {"y", v.y} };
}

inline void from_json(const nlohmann::json& j, Vector2& v) {
    j.at("x").get_to(v.x);
    j.at("y").get_to(v.y);
}
// Vector3.h の後に追加する

// Vector3 用の JSON 変換関数
inline void to_json(nlohmann::json& j, const Vector3& v) {
    j = nlohmann::json{ {"x", v.x}, {"y", v.y}, {"z", v.z} };
}

inline void from_json(const nlohmann::json& j, Vector3& v) {
    j.at("x").get_to(v.x);
    j.at("y").get_to(v.y);
    j.at("z").get_to(v.z);
}




// Item クラス（データの各項目を格納）
class Item {
public:

    std::variant<int32_t, float, Vector3,Vector2> value;  // アイテムの値（int32_t, float, Vector3 など）

    Item() = default;
    Item(int32_t v) : value(v) {}
    Item(float v) : value(v) {}
    Item(Vector3 v) : value(v) {}
    Item(Vector2 v) : value(v) {}

    //// begin と end は std::map から直接取得する
    //std::map<std::string, Item>::iterator begin() {
    //    return items.begin();  // items の最初のイテレータを返す
    //}

    //std::map<std::string, Item>::iterator end() {
    //    return items.end();  // items の最後のイテレータを返す
    //}

};

// Group クラス（グループデータ）
class Group {
public:

    std::map<std::string, Item> items;  // アイテムを格納するマップ

    // グループ内で特定の名前のアイテムを検索
    std::map<std::string, Item>::iterator find(const std::string& itemName) {
        return items.find(itemName);  // アイテム名で検索
    }





    // items の end イテレータを返す
    std::map<std::string, Item>::iterator end() {
        return items.end();  // items の最後のイテレータを返す
    }

};

// GlobalVariables クラス（グループやアイテムの管理）
class GlobalVariables {
public:

    std::map<std::string, Group> datas_;  // グループデータを格納するマップ

    void SaveFile(const std::string& groupName);  // グループデータをファイルに保存
    void LoadFile(const std::string& groupName);  // グループデータをファイルから読み込む
};


// 定数（ディレクトリパスなど）
constexpr const char* kDirectoryPath = "Resources/GlobalVariables/";