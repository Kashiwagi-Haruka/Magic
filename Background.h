#pragma once
#include<Novice.h>
#include "Handle.h"
#include "LRTB.h"

class Background :public Handle
{

private:

	LRTB Pos;
	int handle;

protected:

	Background();
	void BgMove();
	void BgDraw();

	

	


};

