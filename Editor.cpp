//#include "Editor.h"
//
//Editor::Editor() {
//
//
//	// Playerのデータをグループに追加
//	playerGroup.items["Head"] = Item(pl->bonePos[0]);
//	playerGroup.items["Pos2"] = Item(pl->bonePos[1]);
//	playerGroup.items["Pos3"] = Item(pl->bonePos[2]);
//	playerGroup.items["Pos4"] = Item(pl->bonePos[3]);
//	playerGroup.items["Pos5"] = Item(pl->bonePos[4]);
//	playerGroup.items["Pos6"] = Item(pl->bonePos[5]);
//	playerGroup.items["Pos7"] = Item(pl->bonePos[6]);
//	playerGroup.items["Pos8"] = Item(pl->bonePos[7]);
//	playerGroup.items["Pos9"] = Item(pl->bonePos[8]);
//	playerGroup.items["Pos10"] = Item(pl->bonePos[9]);
//	playerGroup.items["Pos11"] = Item(pl->bonePos[10]);
//	playerGroup.items["Pos12"] = Item(pl->bonePos[11]);
//	playerGroup.items["Pos13"] = Item(pl->bonePos[12]);
//	playerGroup.items["Pos14"] = Item(pl->bonePos[13]);
//	playerGroup.items["Pos15"] = Item(pl->bonePos[14]);
//	playerGroup.items["Pos16"] = Item(pl->bonePos[15]);
//	playerGroup.items["Pos17"] = Item(pl->bonePos[16]);
//	playerGroup.items["Pos18"] = Item(pl->bonePos[17]);
//	playerGroup.items["Pos19"] = Item(pl->bonePos[18]);
//	playerGroup.items["Pos20"] = Item(pl->bonePos[19]);
//	playerGroup.items["Pos21"] = Item(pl->bonePos[20]);
//	playerGroup.items["Pos22"] = Item(pl->bonePos[21]);
//	playerGroup.items["Pos23"] = Item(pl->bonePos[22]);
//
//	playerGroup.items["kFaceLeft"] = Item(drawSize[0]);
//	playerGroup.items["kFaceRight"] = Item(drawSize[1]);
//	playerGroup.items["kBangsLeft"] = Item(drawSize[2]);
//	playerGroup.items["kBangsRight"] = Item(drawSize[3]);
//	playerGroup.items["kSidehairLeft"] = Item(drawSize[4]);
//	playerGroup.items["kSidehairRight"] = Item(drawSize[5]);
//	playerGroup.items["kBackhairLeft"] = Item(drawSize[6]);
//	playerGroup.items["kBackhairRight"] = Item(drawSize[7]);
//	playerGroup.items["kEyelidsLeft"] = Item(drawSize[8]);
//	playerGroup.items["kEyelidsRight"] = Item(drawSize[9]);
//	playerGroup.items["kEyeLeft"] = Item(drawSize[10]);
//	playerGroup.items["kEyeRight"] = Item(drawSize[11]);
//	playerGroup.items["kMouseLeft"] = Item(drawSize[12]);
//	playerGroup.items["kMouseRight"] = Item(drawSize[13]);
//
//	playerGroup.items["kClothesLeft"] = Item(drawSize[14]);
//	playerGroup.items["kClothesRight"] = Item(drawSize[15]);
//	playerGroup.items["kArmLeftUP"] = Item(drawSize[16]);
//	playerGroup.items["kArmRightUP"] = Item(drawSize[17]);
//	playerGroup.items["kArmLeftDOWN"] = Item(drawSize[18]);
//	playerGroup.items["kArmRightDOWN"] = Item(drawSize[19]);
//	playerGroup.items["kPantsLeftUP"] = Item(drawSize[20]);
//	playerGroup.items["kPantsRightUP"] = Item(drawSize[21]);
//	playerGroup.items["kPantsLeftDOWN"] = Item(drawSize[22]);
//	playerGroup.items["kPantsRightDOWN"] = Item(drawSize[23]);
//	playerGroup.items["kHat"] = Item(drawSize[24]);
//	
//	// datas_に追加
//	GV->datas_["Player"] = playerGroup;
//
//
//
//}
//
//void Editor::EditorImgui() {
//
//	ImGui::Begin("Player");
//
//	if (ImGui::TreeNodeEx("BonePos")) {
//
//		ImGui::SliderFloat2("Head", &bonePos[0].x, 50.0f, 1280.0f);
//		if (ImGui::TreeNodeEx("Body")) {
//			ImGui::SliderFloat2("Pos2", &bonePos[1].x, 50.0f, 1280.0f);
//			ImGui::SliderFloat2("Pos3", &bonePos[2].x, 50.0f, 1280.0f);
//			ImGui::TreePop();
//		}
//		if (ImGui::TreeNodeEx("LeftArm")) {
//		ImGui::SliderFloat2("Pos4", &bonePos[3].x, 50.0f, 1280.0f);
//		ImGui::SliderFloat2("Pos5", &bonePos[4].x, 50.0f, 1280.0f);
//		ImGui::SliderFloat2("Pos6", &bonePos[5].x, 50.0f, 1280.0f);
//		ImGui::SliderFloat2("Pos7", &bonePos[6].x, 50.0f, 1280.0f);
//		ImGui::SliderFloat2("Pos8", &bonePos[7].x, 50.0f, 1280.0f);
//		ImGui::TreePop();
//		}
//		if (ImGui::TreeNodeEx("RighttArm")) {
//		ImGui::SliderFloat2("Pos9", &bonePos[8].x, 50.0f, 1280.0f);
//		ImGui::SliderFloat2("Pos10", &bonePos[9].x, 50.0f, 1280.0f);
//		ImGui::SliderFloat2("Pos11", &bonePos[10].x, 50.0f, 1280.0f);
//		ImGui::SliderFloat2("Pos12", &bonePos[11].x, 50.0f, 1280.0f);
//		ImGui::SliderFloat2("Pos13", &bonePos[12].x, 50.0f, 1280.0f);
//		ImGui::TreePop();
//		}
//		if (ImGui::TreeNodeEx("LeftLeg")) {
//		ImGui::SliderFloat2("Pos14", &bonePos[13].x, 50.0f, 1280.0f);
//		ImGui::SliderFloat2("Pos15", &bonePos[14].x, 50.0f, 1280.0f);
//		ImGui::SliderFloat2("Pos16", &bonePos[15].x, 50.0f, 1280.0f);
//		ImGui::SliderFloat2("Pos17", &bonePos[16].x, 50.0f, 1280.0f);
//		ImGui::SliderFloat2("Pos18", &bonePos[17].x, 50.0f, 1280.0f);
//		ImGui::TreePop();
//		}
//		if (ImGui::TreeNodeEx("RightLeg")) {
//		ImGui::SliderFloat2("Pos19", &bonePos[18].x, 50.0f, 1280.0f);
//		ImGui::SliderFloat2("Pos20", &bonePos[19].x, 50.0f, 1280.0f);
//		ImGui::SliderFloat2("Pos21", &bonePos[20].x, 50.0f, 1280.0f);
//		ImGui::SliderFloat2("Pos22", &bonePos[21].x, 50.0f, 1280.0f);
//		ImGui::SliderFloat2("Pos23", &bonePos[22].x, 50.0f, 1280.0f);
//		ImGui::TreePop();
//		}
//
//		ImGui::TreePop();
//	}
//	
//	if (ImGui::TreeNodeEx("DrawSize")) {
//		ImGui::SliderFloat2("kFaceLeft", &drawSize[0].x, 0.0f, 1280.0f);
//		ImGui::SliderFloat2("kFaceRight", &drawSize[1].x, 0.0f, 1280.0f);
//		if (ImGui::TreeNodeEx("Hair")) {
//		ImGui::SliderFloat2("kBangsLeft", &drawSize[2].x, 0.0f, 1280.0f);
//		ImGui::SliderFloat2("kBangsRight", &drawSize[3].x, 0.0f, 1280.0f);
//		ImGui::SliderFloat2("kSidehairLeft", &drawSize[4].x, 0.0f, 1280.0f);
//		ImGui::SliderFloat2("kSidehairRight", &drawSize[5].x, 0.0f, 1280.0f);
//		ImGui::SliderFloat2("kBackhairLeft", &drawSize[6].x, 0.0f, 1280.0f);
//		ImGui::SliderFloat2("kBackhairRight", &drawSize[7].x, 0.0f, 1280.0f);
//		ImGui::TreePop();
//		}
//		if (ImGui::TreeNodeEx("EyeMouse")) {
//		ImGui::SliderFloat2("kEyelidsLeft", &drawSize[8].x, 0.0f, 1280.0f);
//		ImGui::SliderFloat2("kEyelidsRight", &drawSize[9].x, 0.0f, 1280.0f);
//		ImGui::SliderFloat2("kEyeLeft", &drawSize[10].x, 0.0f, 1280.0f);
//		ImGui::SliderFloat2("kEyeRight", &drawSize[11].x, 0.0f, 1280.0f);
//		ImGui::SliderFloat2("kMouseLeft", &drawSize[12].x, 0.0f, 1280.0f);
//		ImGui::SliderFloat2("kMouseRight", &drawSize[13].x, 0.0f, 1280.0f);
//		ImGui::TreePop();
//		}
//		if (ImGui::TreeNodeEx("Body")) {
//			ImGui::SliderFloat2("kClothesLeft", &drawSize[14].x, 0.0f, 1280.0f);
//			ImGui::SliderFloat2("kClothesRight", &drawSize[15].x, 0.0f, 1280.0f);
//			ImGui::SliderFloat2("kArmLeftUP", &drawSize[16].x, 0.0f, 1280.0f);
//			ImGui::SliderFloat2("kArmRightUP", &drawSize[17].x, 0.0f, 1280.0f);
//			ImGui::SliderFloat2("kArmLeftDOWN", &drawSize[18].x, 0.0f, 1280.0f);
//			ImGui::SliderFloat2("kArmRightDOWN", &drawSize[19].x, 0.0f, 1280.0f);
//			ImGui::SliderFloat2("kPantsLeftUP", &drawSize[20].x, 0.0f, 1280.0f);
//			ImGui::SliderFloat2("kPantsRightUP", &drawSize[21].x, 0.0f, 1280.0f);
//			ImGui::SliderFloat2("kPantsLeftDOWN", &drawSize[22].x, 0.0f, 1280.0f);
//			ImGui::SliderFloat2("kPantsRightDOWN", &drawSize[23].x, 0.0f, 1280.0f);
//			ImGui::SliderFloat2("kHat", &drawSize[24].x, 0.0f, 1280.0f);
//			ImGui::TreePop();
//		}
//		
//
//
//
//
//
//
//
//
//
//		ImGui::TreePop();
//	}
//
//	if (ImGui::TreeNodeEx("Angle")) {
//
//		ImGui::SliderAngle("angle", &pl->Angle, -180.0f,180.0f);
//
//		ImGui::TreePop();
//	}
//		
//	Novice::ScreenPrintf(0, 0, "pl.Angle::%f", pl->Angle/3.0f);
//		
//		
//		
//		
//
//		
//		
//		
//	
//	ImGui::Text("\n");
//	if (ImGui::Button("Save")) {
//		// Player のデータを更新してから保存
//		playerGroup.items["Head"] = Item(bonePos[0]);
//		playerGroup.items["Pos2"] = Item(bonePos[1]);
//		playerGroup.items["Pos3"] = Item(bonePos[2]);
//		playerGroup.items["Pos4"] = Item(bonePos[3]);
//		playerGroup.items["Pos5"] = Item(bonePos[4]);
//		playerGroup.items["Pos6"] = Item(bonePos[5]);
//		playerGroup.items["Pos7"] = Item(bonePos[6]);
//		playerGroup.items["Pos8"] = Item(bonePos[7]);
//		playerGroup.items["Pos9"] = Item(bonePos[8]);
//		playerGroup.items["Pos10"] = Item(bonePos[9]);
//		playerGroup.items["Pos11"] = Item(bonePos[10]);
//		playerGroup.items["Pos12"] = Item(bonePos[11]);
//		playerGroup.items["Pos13"] = Item(bonePos[12]);
//		playerGroup.items["Pos14"] = Item(bonePos[13]);
//		playerGroup.items["Pos15"] = Item(bonePos[14]);
//		playerGroup.items["Pos16"] = Item(bonePos[15]);
//		playerGroup.items["Pos17"] = Item(bonePos[16]);
//		playerGroup.items["Pos18"] = Item(bonePos[17]);
//		playerGroup.items["Pos19"] = Item(bonePos[18]);
//		playerGroup.items["Pos20"] = Item(bonePos[19]);
//		playerGroup.items["Pos21"] = Item(bonePos[20]);
//		playerGroup.items["Pos22"] = Item(bonePos[21]);
//		playerGroup.items["Pos23"] = Item(bonePos[22]);
//
//		playerGroup.items["kFaceLeft"] = Item(drawSize[0]);
//		playerGroup.items["kFaceRight"] = Item(drawSize[1]);
//		playerGroup.items["kBangsLeft"] = Item(drawSize[2]);
//		playerGroup.items["kBangsRight"] = Item(drawSize[3]);
//		playerGroup.items["kSidehairLeft"] = Item(drawSize[4]);
//		playerGroup.items["kSidehairRight"] = Item(drawSize[5]);
//		playerGroup.items["kBackhairLeft"] = Item(drawSize[6]);
//		playerGroup.items["kBackhairRight"] = Item(drawSize[7]);
//		playerGroup.items["kEyelidsLeft"] = Item(drawSize[8]);
//		playerGroup.items["kEyelidsRight"] = Item(drawSize[9]);
//		playerGroup.items["kEyeLeft"] = Item(drawSize[10]);
//		playerGroup.items["kEyeRight"] = Item(drawSize[11]);
//		playerGroup.items["kMouseLeft"] = Item(drawSize[12]);
//		playerGroup.items["kMouseRight"] = Item(drawSize[13]);
//
//		playerGroup.items["kClothesLeft"] = Item(drawSize[14]);
//		playerGroup.items["kClothesRight"] = Item(drawSize[15]);
//		playerGroup.items["kArmLeftUP"] = Item(drawSize[16]);
//		playerGroup.items["kArmRightUP"] = Item(drawSize[17]);
//		playerGroup.items["kArmLeftDOWN"] = Item(drawSize[18]);
//		playerGroup.items["kArmRightDOWN"] = Item(drawSize[19]);
//		playerGroup.items["kPantsLeftUP"] = Item(drawSize[20]);
//		playerGroup.items["kPantsRightUP"] = Item(drawSize[21]);
//		playerGroup.items["kPantsLeftDOWN"] = Item(drawSize[22]);
//		playerGroup.items["kPantsRightDOWN"] = Item(drawSize[23]);
//		playerGroup.items["kHat"] = Item(drawSize[24]);
//
//		GV->datas_["Player"] = playerGroup;  // 更新されたデータを再設定
//
//		GV->SaveFile("Player");
//
//		
//		std::string message = std::format("{}.json saved.", 42);
//		MessageBoxA(nullptr, message.c_str(), "GlobalVariables", 0);
//	}
//
//	if (ImGui::Button("Load")) {
//		// データを読み込む
//		GV->LoadFile("Player");
//
//		// 読み込んだデータを Player に反映
//		if (GV->datas_.find("Player") != GV->datas_.end()) {
//			playerGroup = GV->datas_["Player"];
//
//			if (playerGroup.items.find("Head") != playerGroup.items.end()) {
//				bonePos[0] = std::get<Vector2>(playerGroup.items["Head"].value);
//			}
//			if (playerGroup.items.find("Pos2") != playerGroup.items.end()) {
//				bonePos[1] = std::get<Vector2>(playerGroup.items["Pos2"].value);
//			}
//			if (playerGroup.items.find("Pos3") != playerGroup.items.end()) {
//				bonePos[2] = std::get<Vector2>(playerGroup.items["Pos3"].value);
//			}
//			if (playerGroup.items.find("Pos4") != playerGroup.items.end()) {
//				bonePos[3] = std::get<Vector2>(playerGroup.items["Pos4"].value);
//			}
//			if (playerGroup.items.find("Pos5") != playerGroup.items.end()) {
//				bonePos[4] = std::get<Vector2>(playerGroup.items["Pos5"].value);
//			}
//			if (playerGroup.items.find("Pos6") != playerGroup.items.end()) {
//				bonePos[5] = std::get<Vector2>(playerGroup.items["Pos6"].value);
//			}
//			if (playerGroup.items.find("Pos7") != playerGroup.items.end()) {
//				bonePos[6] = std::get<Vector2>(playerGroup.items["Pos7"].value);
//			}
//			if (playerGroup.items.find("Pos8") != playerGroup.items.end()) {
//				bonePos[7] = std::get<Vector2>(playerGroup.items["Pos8"].value);
//			}
//			if (playerGroup.items.find("Pos9") != playerGroup.items.end()) {
//				bonePos[8] = std::get<Vector2>(playerGroup.items["Pos9"].value);
//			}
//			if (playerGroup.items.find("Pos10") != playerGroup.items.end()) {
//				bonePos[9] = std::get<Vector2>(playerGroup.items["Pos10"].value);
//			}
//			if (playerGroup.items.find("Pos11") != playerGroup.items.end()) {
//				bonePos[10] = std::get<Vector2>(playerGroup.items["Pos11"].value);
//			}
//			if (playerGroup.items.find("Pos12") != playerGroup.items.end()) {
//				bonePos[11] = std::get<Vector2>(playerGroup.items["Pos12"].value);
//			}
//			if (playerGroup.items.find("Pos13") != playerGroup.items.end()) {
//				bonePos[12] = std::get<Vector2>(playerGroup.items["Pos13"].value);
//			}
//			if (playerGroup.items.find("Pos14") != playerGroup.items.end()) {
//				bonePos[13] = std::get<Vector2>(playerGroup.items["Pos14"].value);
//			}
//			if (playerGroup.items.find("Pos15") != playerGroup.items.end()) {
//				bonePos[14] = std::get<Vector2>(playerGroup.items["Pos15"].value);
//			}
//			if (playerGroup.items.find("Pos16") != playerGroup.items.end()) {
//				bonePos[15] = std::get<Vector2>(playerGroup.items["Pos16"].value);
//			}
//			if (playerGroup.items.find("Pos17") != playerGroup.items.end()) {
//				bonePos[16] = std::get<Vector2>(playerGroup.items["Pos17"].value);
//			}
//			if (playerGroup.items.find("Pos18") != playerGroup.items.end()) {
//				bonePos[17] = std::get<Vector2>(playerGroup.items["Pos18"].value);
//			}
//			if (playerGroup.items.find("Pos19") != playerGroup.items.end()) {
//				bonePos[18] = std::get<Vector2>(playerGroup.items["Pos19"].value);
//			}
//			if (playerGroup.items.find("Pos20") != playerGroup.items.end()) {
//				bonePos[19] = std::get<Vector2>(playerGroup.items["Pos20"].value);
//			}
//			if (playerGroup.items.find("Pos21") != playerGroup.items.end()) {
//				bonePos[20] = std::get<Vector2>(playerGroup.items["Pos21"].value);
//			}
//			if (playerGroup.items.find("Pos22") != playerGroup.items.end()) {
//				bonePos[21] = std::get<Vector2>(playerGroup.items["Pos22"].value);
//			}
//			if (playerGroup.items.find("Pos23") != playerGroup.items.end()) {
//				bonePos[22] = std::get<Vector2>(playerGroup.items["Pos23"].value);
//			}
//
//
//
//			if (playerGroup.items.find("kFaceLeft") != playerGroup.items.end()) {
//				drawSize[0] = std::get<Vector2>(playerGroup.items["kFaceLeft"].value);
//			}
//			if (playerGroup.items.find("kFaceRight") != playerGroup.items.end()) {
//				drawSize[1] = std::get<Vector2>(playerGroup.items["kFaceRight"].value);
//			}
//			if (playerGroup.items.find("kBangsLeft") != playerGroup.items.end()) {
//				drawSize[2] = std::get<Vector2>(playerGroup.items["kBangsLeft"].value);
//			}
//			if (playerGroup.items.find("kBangsRight") != playerGroup.items.end()) {
//				drawSize[3] = std::get<Vector2>(playerGroup.items["kBangsRight"].value);
//			}
//			if (playerGroup.items.find("kSidehairLeft") != playerGroup.items.end()) {
//				drawSize[4] = std::get<Vector2>(playerGroup.items["kSidehairLeft"].value);
//			}
//			if (playerGroup.items.find("kSidehairRight") != playerGroup.items.end()) {
//				drawSize[5] = std::get<Vector2>(playerGroup.items["kSidehairRight"].value);
//			}
//			if (playerGroup.items.find("kBackhairLeft") != playerGroup.items.end()) {
//				drawSize[6] = std::get<Vector2>(playerGroup.items["kBackhairLeft"].value);
//			}
//			if (playerGroup.items.find("kBackhairRight") != playerGroup.items.end()) {
//				drawSize[7] = std::get<Vector2>(playerGroup.items["kBackhairRight"].value);
//			}
//			if (playerGroup.items.find("kEyelidsLeft") != playerGroup.items.end()) {
//				drawSize[8] = std::get<Vector2>(playerGroup.items["kEyelidsLeft"].value);
//			}
//			if (playerGroup.items.find("kEyelidsRight") != playerGroup.items.end()) {
//				drawSize[9] = std::get<Vector2>(playerGroup.items["kEyelidsRight"].value);
//			}
//			if (playerGroup.items.find("kEyeLeft") != playerGroup.items.end()) {
//				drawSize[10] = std::get<Vector2>(playerGroup.items["kEyeLeft"].value);
//			}
//			if (playerGroup.items.find("kEyeRight") != playerGroup.items.end()) {
//				drawSize[11] = std::get<Vector2>(playerGroup.items["kEyeRight"].value);
//			}
//			if (playerGroup.items.find("kMouseLeft") != playerGroup.items.end()) {
//				drawSize[12] = std::get<Vector2>(playerGroup.items["kMouseLeft"].value);
//			}
//			if (playerGroup.items.find("kMouseRight") != playerGroup.items.end()) {
//				drawSize[13] = std::get<Vector2>(playerGroup.items["kMouseRight"].value);
//			}
//			if (playerGroup.items.find("kClothesLeft") != playerGroup.items.end()) {
//				drawSize[14] = std::get<Vector2>(playerGroup.items["kClothesLeft"].value);
//			}
//			if (playerGroup.items.find("kClothesRight") != playerGroup.items.end()) {
//				drawSize[15] = std::get<Vector2>(playerGroup.items["kClothesRight"].value);
//			}
//			if (playerGroup.items.find("kArmLeftUP") != playerGroup.items.end()) {
//				drawSize[16] = std::get<Vector2>(playerGroup.items["kArmLeftUP"].value);
//			}
//			if (playerGroup.items.find("kArmRightUP") != playerGroup.items.end()) {
//				drawSize[17] = std::get<Vector2>(playerGroup.items["kArmRightUP"].value);
//			}
//			if (playerGroup.items.find("kArmLeftUP") != playerGroup.items.end()) {
//				drawSize[18] = std::get<Vector2>(playerGroup.items["kArmLeftUP"].value);
//			}
//			if (playerGroup.items.find("kArmRightUP") != playerGroup.items.end()) {
//				drawSize[19] = std::get<Vector2>(playerGroup.items["kArmRightUP"].value);
//			}
//			if (playerGroup.items.find("kPantsLeftUP") != playerGroup.items.end()) {
//				drawSize[20] = std::get<Vector2>(playerGroup.items["kPantsLeftUP"].value);
//			}
//			if (playerGroup.items.find("kPantsRightUP") != playerGroup.items.end()) {
//				drawSize[21] = std::get<Vector2>(playerGroup.items["kPantsRightUP"].value);
//			}
//			if (playerGroup.items.find("kPantsLeftDOWN") != playerGroup.items.end()) {
//				drawSize[22] = std::get<Vector2>(playerGroup.items["kPantsLeftDOWN"].value);
//			}
//			if (playerGroup.items.find("kPantsRightDOWN") != playerGroup.items.end()) {
//				drawSize[23] = std::get<Vector2>(playerGroup.items["kPantsRightDOWN"].value);
//			}
//			if (playerGroup.items.find("kHat") != playerGroup.items.end()) {
//				drawSize[24] = std::get<Vector2>(playerGroup.items["kHat"].value);
//			}
//			
//			
//				
//
//
//				
//				
//				
//				
//				
//				
//				
//				
//				
//
//
//			printf("Player data loaded and applied.\n");
//		}
//	}
//
//	
//
//
//	ImGui::End();
//
//	
//	
//	
//}
//
//
