#pragma once
#include <Vector2.h>
struct LRTB
{
	Vector2 LeftTop;//1
	Vector2 RightTop;//2
	Vector2 LeftButtom;//3
	Vector2 RightButtom;//4

};
void LRTBdrawQuad(LRTB pos, LRTB drawPos, int Handle, int color);
