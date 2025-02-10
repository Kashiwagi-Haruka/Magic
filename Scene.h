#pragma once
#include "Background.h"
#include "Player.h"
#include "Line.h"
#include <Novice.h>
#include "Select.h"
#include "Enemy.h"
#include "Title.h"
#include "Result.h"

class Scene:private Background,Line,Player,Select,Title,Enemy,Result
{
private:

	

	enum SceneNo
	{
		ktitle=0,
		kselect,
		kstage1,
		kstage2,
		kstage3,
		kresult,
	};

	SceneNo sceneNo;

	int score;
	int Timer;

	int handls;

	Vector2 drawPos[5];
	Vector2 drawsize[5];

	void EBHit();
	void PEHit();
	void RESET();

	unsigned int currentTime;


public:

	Scene();
	
	void UPDATE(char *keys,char* preKeys);
	
};

