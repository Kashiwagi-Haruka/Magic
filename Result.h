#pragma once
#include "LRTB.h"
#include "Novice.h"
#include "Handle.h"
class Result :Handle
{
private:

	int Score;
	int FirstNo;
	int SecondNo;
	int ThirdNo;
	int ForthNo;
	int FivethNo;

	LRTB drawPos;

	LRTB BGPos;

	int handle[3];

public:

	Result();

	void SetScore(int score);
	void ResultMove();
	void ResultNoDraw(int No,Vector2 pos);
	void ResultDraw();
};

