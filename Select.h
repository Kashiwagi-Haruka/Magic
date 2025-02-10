#pragma once
#include "Handle.h"
class Select :Handle
{
private:

	int stageNo;
	int stageMax;

public:

	void SetStageSelect();
	void SelectMove(char*keys,char*preKeys);
	void SelectDraw();

};

