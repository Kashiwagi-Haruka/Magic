#include "Enemy.h"

Enemy::Enemy() {
	for (int i = 0; i < 3; i++) {
		isAlive[i] = true;
		Size[i] = {100,100};
		HitEnemyPos[i] = pos[i].LeftTop;
		RespornTimer[i] = 0;
		isRespornTimer[i] = false;
		speed = 0;
		wvpVpMatrix = {};
		HitSize[i] = {90.0f,90.0f};
		pos[i] = {{0,Size[i].y},{Size[i]}, {0,0},{Size[i].x,0}};
		drawPos[i] = {{0,0},{},{},{2048,2048}};
		screenPos[i] = {};
		Handle_ = GetHandle(kEnemy);
		action = kWait;
		ActionT = 0.0f;
		pos[i].LeftTop.x = 1000;
		pos[i].LeftButtom.x = 1000;
		pos[i].RightButtom.x = 1000 + Size[i].x;
		pos[i].RightTop.x = 1000 + Size[i].x;
	}
}

void Enemy::EnemyMove() {

	wvpVpMatrix = GetwvpVpMatrix();
	
	ActionT += 0.01f;
	Handle_ = GetHandle(kEnemy);
		
	
	for (int i = 0; i < 3; i++) {
		pos[i].LeftTop.y = EaseInOut(400.0f + Size[i].y - (i) * 200, 500.0f + Size[i].y- (i) *200, ActionT);
		pos[i].RightTop.y = EaseInOut(400.0f + Size[i].y - (i) * 200, 500.0f + Size[i].y - (i) * 200, ActionT);
		pos[i].LeftButtom.y = EaseInOut(400.0f - (i) * 200, 500.0f - (i) * 200, ActionT);
		pos[i].RightButtom.y = EaseInOut(400.0f - (i) * 200, 500.0f - (i) * 200, ActionT);
	}
	switch (action)
	{
	case Enemy::kWait:
		



		break;
	case Enemy::kAttuck:


		break;
	default:
		break;
	}

	for (int i = 0; i < 3; i++) {
		
		if (isRespornTimer[i]) {
			RespornTimer[i]++;
			
		} else {
			RespornTimer[i] = 0;
		}
		if (RespornTimer[i] >= 60) {
			isRespornTimer[i] = false;
			isAlive[i] = true;
		}

	}

	for (int i = 0; i < 3; i++) {
		HitEnemyPos[i].x = (pos[i].LeftTop.x + pos[i].LeftButtom.x + pos[i].RightTop.x + pos[i].RightButtom.x) / 4.0f;
		HitEnemyPos[i].y = (pos[i].LeftTop.y + pos[i].LeftButtom.y + pos[i].RightTop.y + pos[i].RightButtom.y) / 4.0f;

		screenPos[i].LeftTop = Transform(pos[i].LeftTop, wvpVpMatrix);
		screenPos[i].LeftButtom = Transform(pos[i].LeftButtom, wvpVpMatrix);
		screenPos[i].RightTop = Transform(pos[i].RightTop, wvpVpMatrix);
		screenPos[i].RightButtom = Transform(pos[i].RightButtom, wvpVpMatrix);
	}
}
void Enemy::EnemyDraw() {
	for (int i = 0; i < 3; i++) {
		if (isAlive[i]) {
			LRTBdrawQuad(screenPos[i], drawPos[i], Handle_, 0xffffffff);
		}
	}

}
void Enemy::SetEnemyIsAlive(bool isalive,int Eno) {
	
		isAlive[Eno] = isalive;
	

}
void Enemy::SetEnemyIsRespornTimer(bool isresTimer,int Eno) {

	isRespornTimer[Eno] = isresTimer;

}

void Enemy::Reset() {
	for (int i = 0; i < 3; i++) {
		isAlive[i] = true;
		Size[i] = { 100,100 };
		HitEnemyPos[i] = pos[i].LeftTop;
		RespornTimer[i] = 0;
		isRespornTimer[i] = false;
		speed = 0;
		wvpVpMatrix = {};
		HitSize[i] = { 90.0f,90.0f };
		pos[i] = { {0,Size[i].y},{Size[i]}, {0,0},{Size[i].x,0} };
		drawPos[i] = { {0,0},{},{},{2048,2048} };
		screenPos[i] = {};
		Handle_ = GetHandle(kEnemy);
		action = kWait;
		ActionT = 0.0f;
		pos[i].LeftTop.x = 1000;
		pos[i].LeftButtom.x = 1000;
		pos[i].RightButtom.x = 1000 + Size[i].x;
		pos[i].RightTop.x = 1000 + Size[i].x;
	}
}