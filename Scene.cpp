#include "Scene.h"

Scene::Scene() {

	Timer = 0;
	
	score = 0;

	sceneNo = ktitle;

	drawPos[0] = {181,0};
	drawPos[1] = {15,166};
	drawPos[2] = {181,166};
	drawPos[3] = {364,166};
	drawPos[4] = {0,400};
	
	drawsize[0] = { 368-181,170 };
	drawsize[1] = { 170,185 };
	drawsize[2] = { 170,185 };
	drawsize[3] = { 170,185 };
	drawsize[4] = { 615,158 };

	currentTime = int(time(nullptr));
	
	handls = Handle::GetHandle(kKeys);

	srand(currentTime);

}

void Scene::UPDATE(char* keys, char* preKeys) {

	if (keys[DIK_R] && !preKeys[DIK_R]) {
		RESET();
	}

	switch (sceneNo)
	{
	case ktitle:
		Timer = 0;
		TitleDraw();

		if (!preKeys[DIK_SPACE] && keys[DIK_SPACE]) {
			RESET();
			sceneNo = kstage1;
		}

		break;

	case kstage1:

		Timer++;


		BgMove();
		Player::PlMove(keys, preKeys);
		Player::PlAnimation(keys);
		LiMove();
		EnemyMove();
		PEHit();
		EBHit();




		LiDraw();
		BgDraw();
		Player::PlDraw();
		EnemyDraw();

		if (Timer >= 10/*s*/ * 60/*flame*/) {
			sceneNo = kresult;
		}
		if (GetIsDead()) {
			sceneNo = kresult;
		}

		break;

	case kresult:
		SetScore(score);
		ResultMove();
		ResultDraw();

		if (!preKeys[DIK_SPACE] && keys[DIK_SPACE]) {
			sceneNo = ktitle;
		}

		break;
	default:
		break;
	}
	
	if (keys[DIK_W]) {
		drawPos[0].x = 181+519;
	} else {
		drawPos[0].x = 181;
	}
	if (keys[DIK_A]) {
		drawPos[1].x = 534;
	} else {
		drawPos[1].x = 15;
	}
	if (keys[DIK_S]) {
		drawPos[2].x = 190+519;
	} else {
		drawPos[2].x = 190;
	}
	if (keys[DIK_D]) {
		drawPos[3].x = 364+519;
	} else {
		drawPos[3].x = 364;
	}

	if (keys[DIK_SPACE]) {
		drawPos[4].y = 555;
	} else {
		drawPos[4].y = 400;
	}
	LRTBdrawQuad({ { 120.0f,580 },{ 180.0f,580 } ,{ 120.0f,640 } ,{ 180.0f,640 } }, { { drawPos[0] },{},{} ,{drawsize[0]} }, handls, 0xffffffff);
	for (int i = 1; i < 4; i++) {
		LRTBdrawQuad({ { 0.0f + i * 60,640 },{ 60.0f+i*60,640 } ,{ 0.0f + i * 60,700 } ,{ 60.0f + i * 60,700 } }, { { drawPos[i] },{},{} ,{drawsize[i]} }, handls, 0xffffffff);
	}
	LRTBdrawQuad({ {250,640},{450,640},{250,700},{450,700} }, { drawPos[4],{} ,{},{drawsize[4]} }, handls, 0xffffffff);
}

void Scene::PEHit() {
	Vector2 length[3]{};
	Vector2 size[3]{};

	for (int ENo = 0; ENo < 3; ENo++) {
		if (GetEnemyIsAlive(ENo)) {
			length[ENo].x = powf(GetEnemyPos(ENo).x - GetMiddlePos().x, 2.0f);
			length[ENo].y = powf(GetEnemyPos(ENo).y - GetMiddlePos().y, 2.0f);

			size[ENo].x = (GetEnemySize(ENo).x + bullet.GetBuletSize().x);
			size[ENo].y = (GetEnemySize(ENo).y + bullet.GetBuletSize().y);
			if (length[ENo].x + length[ENo].y <= size[ENo].x * size[ENo].y) {
				if (!GetIsDamage()) {
					SetHP(-1);
					score -= 200;
					SetIsDamage(true);
				}
			}
		}
	}

}

void Scene::EBHit() {
	Vector2 length[3][4][15]{};
	Vector2 size[3]{};



	for (int ENo = 0; ENo < 3; ENo++) {
		if (GetEnemyIsAlive(ENo)) {
			for (int suit = 0; suit < 4; suit++) {
				for (int BNo = 0; BNo < 15; BNo++) {
					length[ENo][suit][BNo].x = powf(GetEnemyPos(ENo).x - bullet.GetBulletPos(suit, BNo).x, 2.0f);
					length[ENo][suit][BNo].y = powf(GetEnemyPos(ENo).y - bullet.GetBulletPos(suit, BNo).y, 2.0f);

					size[ENo].x = (GetEnemySize(ENo).x + bullet.GetBuletSize().x);
					size[ENo].y = (GetEnemySize(ENo).y + bullet.GetBuletSize().y);

					if (length[ENo][suit][BNo].x + length[ENo][suit][BNo].y <= size[ENo].x * size[ENo].y) {
						score += 200;

						bullet.SetIsHitEffct(true, suit, BNo);

						Enemy::SetEnemyIsAlive(false, ENo);
						SetEnemyIsRespornTimer(true,ENo);
						bullet.SetBulletIsAlive(false, suit, BNo);
					}


					/*Novice::ScreenPrintf(500, 0, "%.0f:%.0f:%.0f", length[0][0][0].x, length[0][0][0].y, length[0][0][0].x + length[0][0][0].y);
					Novice::ScreenPrintf(500, 20, "%.0f:%.0f:%.0f", size[0].x , size[0].y, size[0].x * size[0].y);
					Novice::ScreenPrintf(500, 40, "%.0f:%.0f: :%.0f:%.0f", (GetEnemyPos(0).x, GetEnemyPos(0).y, bullet.GetBulletPos(0,0).x, bullet.GetBulletPos(0, 0).y));*/
				}
			}
		}
	}




}

void Scene::RESET() {

	Player::Reset();
	Enemy::Reset();
	Timer = 0;
	score = 0;

}