#include "Select.h"

void Select::SelectMove(char*keys,char *preKeys) {

	if ((!preKeys[DIK_W] && keys[DIK_W]) || (!preKeys[DIK_A] && keys[DIK_A]) || (!preKeys[DIK_UP] && keys[DIK_UP])) {
		stageNo--;
	}
	if ((!preKeys[DIK_S] && keys[DIK_S]) || (!preKeys[DIK_D] && keys[DIK_D]) || (!preKeys[DIK_DOWN] && keys[DIK_DOWN])) {
		stageNo++;
	}

	if (stageNo < 0) {
		stageNo = stageMax;
	}
	if (stageNo > stageMax) {
		stageNo = 0;
	}


}