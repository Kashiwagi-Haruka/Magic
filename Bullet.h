#pragma once
#include "Handle.h"
#include "Camera.h"
#include "LRTB.h"
class Bullet:Handle
{
	
private:

	enum Suit {

		SPADE,
		HEART,
		DIAMOND,
		CLUB,

	};

	LRTB pos[4][15];
	LRTB ScreenPos[4][15];
	Vector2 HitPos[4][15];

	LRTB drawPos[4];

	Vector2 size;
	bool isAlive[4][15];

	float speed;

	bool isShot;
	bool isShotCoolTime;
	int shotCoolTime;

	Camera camera;

	Matrix3x3 wvpVpMatrix;

	int handle;
	int color;


	bool IsHitEffct[4][15];

	Vector2 HitEffectPos[15][20];
	Vector2 HitEffectsize[15][20];

	int HitEffectcolor[4];
	float HitEffectT[15];

	Vector2 playerPos;

public:


	void Init();

	void Move(char* keys, char* preKeys);
	void Draw();

	
	void HitEffect(int HitNo);

	void SetPlayerPos(Vector2 playerpos_);

	Vector2 GetBulletPos(int suit, int BNo) { return HitPos[suit][BNo]; };
	Vector2 GetBuletSize() { return size; };
	void SetIsHitEffct(bool ishitE, int suit, int ENo);
	void SetBulletIsAlive(bool isalive, int suit, int BNo);
	
};

