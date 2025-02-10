#pragma once
#include "Camera.h"
#include "Handle.h"
class Title: private Handle,Camera
{
private:

	Vector2 pos;

	int Handle_[2];
	int color;


public:

	Title();
	void TitleMove();
	void TitleDraw();

};

