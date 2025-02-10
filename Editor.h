#pragma once
#include "GlobalVariables.h"
#include "Player.h"

class Editor:public Player
{
public:

	Editor();
	
	void EditorImgui();

private:

	Player* pl = new Player;
	

	GlobalVariables* GV = new GlobalVariables;

	Group playerGroup;
	
	

};

