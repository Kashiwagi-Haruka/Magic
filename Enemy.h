#pragma once
#include "LRTB.h"
#include "Camera.h"
#include "Handle.h"
class Enemy:Handle,Camera
{
private:

	LRTB pos[3];
	LRTB screenPos[3];
	LRTB drawPos[3];
	Vector2 Size[3];
	Vector2 HitEnemyPos[3];
	Vector2 HitSize[3];

	Matrix3x3 wvpVpMatrix;

	int Handle_;

	int isAlive[3];
	int RespornTimer[3];

	bool isRespornTimer[3];

	float speed;

	enum Action
	{
		kWait,
		kAttuck,
	};

	Action action;
	float ActionT;

public:

	Enemy();
	Vector2 GetEnemyPos(int ENo) { return HitEnemyPos[ENo]; };
	Vector2 GetEnemySize(int ENo) { return HitSize[ENo]; };
	void SetEnemyIsAlive(bool isAlive,int Eno);
	void EnemyMove();
	void EnemyDraw();
	bool GetEnemyIsAlive(int ENo) { return isAlive[ENo]; };
	void  SetEnemyIsRespornTimer(bool isresTimer,int ENo);

	void Reset();
};

