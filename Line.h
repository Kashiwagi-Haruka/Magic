#pragma once
#include <Vector2.h>
#include "Camera.h"
#include <Novice.h>

class Line:Camera
{
private:
	Vector2 pos[2][2];
	Vector2 screenPos[2][2];


	Matrix3x3 wvpVpMatrix;

	

public:
	Line();
	void LiMove();
	void LiDraw();

};

