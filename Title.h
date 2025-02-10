#pragma once
#include "Camera.h"
#include "Handle.h"
class Title: private Handle,Camera
{
	Vector2 pos;

	int Handle_;
	int color;


public:

	Title();
	void TitleMove();
	void TitleDraw();

};

