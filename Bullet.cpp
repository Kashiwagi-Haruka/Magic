#include "Bullet.h"

void Bullet::Init() {

	handle = GetHandle(kBullet);
	for (int s = Suit::SPADE; s <= Suit::CLUB; s++) {
		for (int i = 0; i < 15; i++) {
			pos[s][i] = {};
			isAlive[s][i] = false;
		}
	}
	speed = 8.0f;
	size = { 20.0f,20.0f };
	shotCoolTime = 0;
	for (int s = Suit::SPADE; s <= Suit::CLUB; s++) {
		for (int i = 0; i < 15; i++) {
			IsHitEffct[s][i] = false;
			HitEffectsize[s][i] = { 5.0f ,5.0f};
			HitEffectT[s] = 0.0f;
		}
	}
	
}
void Bullet::Move(char* keys,char* preKeys) {

	if (!preKeys) {

	}

	wvpVpMatrix = camera.GetwvpVpMatrix();

	

	if (keys[DIK_SPACE]) {

		isShot = true;

	} else {
		isShot = false;
	}

	if (isShot) {
		
			for (int s = Suit::SPADE; s <= Suit::CLUB; s++) {
				for (int i = 0; i < 15; i++) {
					
					if (!isAlive[s][i]) {
						if (!isShotCoolTime) {
							isAlive[s][i] = true;
							isShotCoolTime = true;
						}
					}
					

				}
			}
		
			if (isShotCoolTime) {
				
				if (shotCoolTime >= 20) {
					shotCoolTime = 0;
					isShotCoolTime = false;
				} else {
					shotCoolTime++;
				}
			}

	} else {
		isShotCoolTime = false;
	}

	

	for (int s = Suit::SPADE; s <= Suit::CLUB; s++) {
		for (int i = 0; i < 15; i++) {
		
			if (isAlive[s][i]) {
				pos[s][i].LeftTop.x += speed;
				if (ScreenPos[s][i].LeftTop.x >= 1280.0f) {

					isAlive[s][i] = false;
					pos[s][i].LeftTop = playerPos;
				}
			} else {
				pos[s][i].LeftTop = playerPos;
			}

		}
	}


	for (int s = Suit::SPADE; s <= Suit::CLUB; s++) {
		for (int i = 0; i < 15; i++) {
			/*HitPos[s][i].x = (pos[s][i].LeftTop.x + pos[s][i].LeftButtom.x + pos[s][i].RightTop.x + pos[s][i].RightButtom.x) / 4.0f;
			HitPos[s][i].y = (pos[s][i].LeftTop.y + pos[s][i].LeftButtom.y + pos[s][i].RightTop.y + pos[s][i].RightButtom.y) / 4.0f;*/
			HitPos[s][i].x = pos[s][i].LeftTop.x;
			HitPos[s][i].y = pos[s][i].LeftTop.y;
		}
	}
	
	for (int s = Suit::SPADE; s <= Suit::CLUB; s++) {
		for (int i = 0; i < 15; i++) {
			ScreenPos[s][i].LeftTop = Transform(pos[s][i].LeftTop, wvpVpMatrix);
			ScreenPos[s][i].LeftButtom = Transform(pos[s][i].LeftButtom, wvpVpMatrix);
			ScreenPos[s][i].RightTop = Transform(pos[s][i].RightTop, wvpVpMatrix);
			ScreenPos[s][i].RightButtom = Transform(pos[s][i].RightButtom, wvpVpMatrix);
		}
	}
	for (int s = Suit::SPADE; s <= Suit::CLUB; s++) {
		for (int i = 0; i < 15; i++) {
			if (IsHitEffct[s][i]) {
				HitEffect(0);
			}
		}
	}

}


void Bullet::Draw() {
	
	
	
		for (int i = 0; i < 15; i++) {
			if (isAlive[Suit::SPADE][i]) {
				/*LRTBdrawQuad(ScreenPos[s][i], drawPos[s], handle, color);*/
				Novice::DrawEllipse(int(ScreenPos[Suit::SPADE][i].LeftTop.x), int(ScreenPos[Suit::SPADE][i].LeftTop.y), 20, 20, 0.0f, 0x3333ffff, kFillModeSolid);
				Novice::DrawEllipse(int(ScreenPos[Suit::HEART ][i].LeftTop.x), int(ScreenPos[Suit::HEART][i].LeftTop.y), 20, 20, 0.0f, 0xff3333ff, kFillModeSolid);
				Novice::DrawEllipse(int(ScreenPos[Suit::DIAMOND][i].LeftTop.x), int(ScreenPos[Suit::DIAMOND][i].LeftTop.y), 20, 20, 0.0f, 0xffff33ff, kFillModeSolid);
				Novice::DrawEllipse(int(ScreenPos[Suit::CLUB][i].LeftTop.x), int(ScreenPos[Suit::CLUB][i].LeftTop.y), 20, 20, 0.0f, 0x33ff33ff, kFillModeSolid);

				

				

			}
		}
	
	/*for (int s = Suit::SPADE; s <= Suit::CLUB; s++) {
		for (int i = 0; i < 15; i++) {
			if (IsHitEffct[s][i]) {

		
				for (int j = 0; j < 20; j++) {
				
					Novice::DrawEllipse(static_cast<int>(HitEffectPos[i][j].x), static_cast<int>(HitEffectPos[i][j].y), static_cast<int>(HitEffectsize[i][j].x), static_cast<int>(HitEffectsize[i][j].y), 0.0f, HitEffectcolor[s], kFillModeSolid);
				}
			
			}
		}
	}*/

}

void Bullet::SetBulletIsAlive(bool isalive, int suit, int BNo) {

	isAlive[suit][BNo] = isalive;
}

void Bullet::SetIsHitEffct(bool ishitE,int suit,int ENo) {

	IsHitEffct[suit][ENo] = ishitE;

}

void Bullet::HitEffect(int HitNo) {
	
	if (HitEffectT[HitNo] < 1.0f) {
		HitEffectT[HitNo] += 0.01f;
	}

		if (IsHitEffct[Suit::SPADE][HitNo]) {

			HitEffectPos[HitNo][0].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x - 0.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][1].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x - 13.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][2].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x - 27.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][3].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x - 39.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][4].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x - 53.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][5].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x - 53.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][6].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x - 24.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][7].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x - 9.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][8].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x - 0.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][9].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x - 5.0f, HitEffectT[HitNo]);

			HitEffectPos[HitNo][10].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x + 0.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][11].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x + 13.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][12].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x + 27.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][13].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x + 39.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][14].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x + 53.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][15].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x + 53.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][16].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x + 24.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][17].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x + 9.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][18].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x + 0.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][19].x = EaseOut(HitPos[Suit::SPADE][HitNo].x, HitPos[Suit::SPADE][HitNo].x + 5.0f, HitEffectT[HitNo]);

			HitEffectPos[HitNo][0].y = EaseOut(HitPos[Suit::SPADE][HitNo].y, HitPos[Suit::SPADE][HitNo].y - 0.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][1].y = EaseOut(HitPos[Suit::SPADE][HitNo].y, HitPos[Suit::SPADE][HitNo].y - 13.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][2].y = EaseOut(HitPos[Suit::SPADE][HitNo].y, HitPos[Suit::SPADE][HitNo].y - 27.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][3].y = EaseOut(HitPos[Suit::SPADE][HitNo].y, HitPos[Suit::SPADE][HitNo].y - 39.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][4].y = EaseOut(HitPos[Suit::SPADE][HitNo].y, HitPos[Suit::SPADE][HitNo].y - 53.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][5].y = EaseOut(HitPos[Suit::SPADE][HitNo].y, HitPos[Suit::SPADE][HitNo].y - 53.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][6].y = EaseOut(HitPos[Suit::SPADE][HitNo].y, HitPos[Suit::SPADE][HitNo].y - 24.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][7].y = EaseOut(HitPos[Suit::SPADE][HitNo].y, HitPos[Suit::SPADE][HitNo].y - 9.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][8].y = EaseOut(HitPos[Suit::SPADE][HitNo].y, HitPos[Suit::SPADE][HitNo].y - 0.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][9].y = EaseOut(HitPos[Suit::SPADE][HitNo].y, HitPos[Suit::SPADE][HitNo].y - 5.0f, HitEffectT[HitNo]);

			for (int i = 0; i < 10; i ++) {
				HitEffectPos[HitNo][i+10].y = HitEffectPos[HitNo][i].y;
			}
			

		} else if (IsHitEffct[Suit::HEART][HitNo]) {

			HitEffectPos[HitNo][0].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x - 10.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][1].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x - 20.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][2].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x - 43.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][3].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x - 69.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][4].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x - 54.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][5].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x - 69.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][6].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x - 54.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][7].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x - 44.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][8].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x - 25.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][9].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x - 0.0f, HitEffectT[HitNo]);

			HitEffectPos[HitNo][10].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x + 10.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][11].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x + 20.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][12].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x + 43.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][13].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x + 69.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][14].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x + 54.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][15].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x + 69.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][16].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x + 54.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][17].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x + 44.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][18].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x + 25.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][19].x = EaseOut(HitPos[Suit::HEART][HitNo].x, HitEffectPos[Suit::HEART][HitNo].x + 0.0f, HitEffectT[HitNo]);

			HitEffectPos[HitNo][0].y = EaseOut(HitPos[Suit::HEART][HitNo].y, HitEffectPos[Suit::HEART][HitNo].y - 10.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][1].y = EaseOut(HitPos[Suit::HEART][HitNo].y, HitEffectPos[Suit::HEART][HitNo].y - 20.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][2].y = EaseOut(HitPos[Suit::HEART][HitNo].y, HitEffectPos[Suit::HEART][HitNo].y - 43.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][3].y = EaseOut(HitPos[Suit::HEART][HitNo].y, HitEffectPos[Suit::HEART][HitNo].y - 69.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][4].y = EaseOut(HitPos[Suit::HEART][HitNo].y, HitEffectPos[Suit::HEART][HitNo].y - 54.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][5].y = EaseOut(HitPos[Suit::HEART][HitNo].y, HitEffectPos[Suit::HEART][HitNo].y - 69.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][6].y = EaseOut(HitPos[Suit::HEART][HitNo].y, HitEffectPos[Suit::HEART][HitNo].y - 54.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][7].y = EaseOut(HitPos[Suit::HEART][HitNo].y, HitEffectPos[Suit::HEART][HitNo].y - 44.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][8].y = EaseOut(HitPos[Suit::HEART][HitNo].y, HitEffectPos[Suit::HEART][HitNo].y - 25.0f, HitEffectT[HitNo]);
			HitEffectPos[HitNo][9].y = EaseOut(HitPos[Suit::HEART][HitNo].y, HitEffectPos[Suit::HEART][HitNo].y - 0.0f, HitEffectT[HitNo]);

			for (int i = 0; i < 10; i++) {
				HitEffectPos[HitNo][i + 10].y = HitEffectPos[HitNo][i].y;
			}

		} else if (IsHitEffct[Suit::DIAMOND][HitNo]) {

			HitEffectPos[HitNo][0].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x - 0, HitEffectT[HitNo]);
			HitEffectPos[HitNo][1].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x - 9, HitEffectT[HitNo]);
			HitEffectPos[HitNo][2].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x - 18, HitEffectT[HitNo]);
			HitEffectPos[HitNo][3].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x - 31, HitEffectT[HitNo]);
			HitEffectPos[HitNo][4].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x - 44, HitEffectT[HitNo]);
			HitEffectPos[HitNo][5].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x - 57, HitEffectT[HitNo]);
			HitEffectPos[HitNo][6].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x - 40, HitEffectT[HitNo]);
			HitEffectPos[HitNo][7].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x - 22, HitEffectT[HitNo]);
			HitEffectPos[HitNo][8].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x - 13, HitEffectT[HitNo]);
			HitEffectPos[HitNo][9].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x - 0, HitEffectT[HitNo]);

			HitEffectPos[HitNo][10].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x + 0, HitEffectT[HitNo]);
			HitEffectPos[HitNo][11].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x + 9, HitEffectT[HitNo]);
			HitEffectPos[HitNo][12].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x + 18, HitEffectT[HitNo]);
			HitEffectPos[HitNo][13].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x + 31, HitEffectT[HitNo]);
			HitEffectPos[HitNo][14].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x + 44, HitEffectT[HitNo]);
			HitEffectPos[HitNo][15].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x + 57, HitEffectT[HitNo]);
			HitEffectPos[HitNo][16].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x + 40, HitEffectT[HitNo]);
			HitEffectPos[HitNo][17].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x + 22, HitEffectT[HitNo]);
			HitEffectPos[HitNo][18].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x + 13, HitEffectT[HitNo]);
			HitEffectPos[HitNo][19].x = EaseOut(HitPos[Suit::DIAMOND][HitNo].x, HitEffectPos[Suit::DIAMOND][HitNo].x + 0, HitEffectT[HitNo]);

			HitEffectPos[HitNo][0].y = EaseOut(HitPos[Suit::DIAMOND][HitNo].y, HitEffectPos[Suit::DIAMOND][HitNo].y - 0, HitEffectT[HitNo]);
			HitEffectPos[HitNo][1].y = EaseOut(HitPos[Suit::DIAMOND][HitNo].y, HitEffectPos[Suit::DIAMOND][HitNo].y - 9, HitEffectT[HitNo]);
			HitEffectPos[HitNo][2].y = EaseOut(HitPos[Suit::DIAMOND][HitNo].y, HitEffectPos[Suit::DIAMOND][HitNo].y - 18, HitEffectT[HitNo]);
			HitEffectPos[HitNo][3].y = EaseOut(HitPos[Suit::DIAMOND][HitNo].y, HitEffectPos[Suit::DIAMOND][HitNo].y - 31, HitEffectT[HitNo]);
			HitEffectPos[HitNo][4].y = EaseOut(HitPos[Suit::DIAMOND][HitNo].y, HitEffectPos[Suit::DIAMOND][HitNo].y - 44, HitEffectT[HitNo]);
			HitEffectPos[HitNo][5].y = EaseOut(HitPos[Suit::DIAMOND][HitNo].y, HitEffectPos[Suit::DIAMOND][HitNo].y - 57, HitEffectT[HitNo]);
			HitEffectPos[HitNo][6].y = EaseOut(HitPos[Suit::DIAMOND][HitNo].y, HitEffectPos[Suit::DIAMOND][HitNo].y - 40, HitEffectT[HitNo]);
			HitEffectPos[HitNo][7].y = EaseOut(HitPos[Suit::DIAMOND][HitNo].y, HitEffectPos[Suit::DIAMOND][HitNo].y - 22, HitEffectT[HitNo]);
			HitEffectPos[HitNo][8].y = EaseOut(HitPos[Suit::DIAMOND][HitNo].y, HitEffectPos[Suit::DIAMOND][HitNo].y - 13, HitEffectT[HitNo]);
			HitEffectPos[HitNo][9].y = EaseOut(HitPos[Suit::DIAMOND][HitNo].y, HitEffectPos[Suit::DIAMOND][HitNo].y - 0, HitEffectT[HitNo]);

			for (int i = 0; i < 10; i++) {
				HitEffectPos[HitNo][i + 10].y = HitEffectPos[HitNo][i].y;
			}

		} else if (IsHitEffct[Suit::CLUB ][HitNo]) {

			HitEffectPos[HitNo][0].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x - 0, HitEffectT[HitNo]);
			HitEffectPos[HitNo][1].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x - 22, HitEffectT[HitNo]);
			HitEffectPos[HitNo][2].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x - 18, HitEffectT[HitNo]);
			HitEffectPos[HitNo][3].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x - 31, HitEffectT[HitNo]);
			HitEffectPos[HitNo][4].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x - 53, HitEffectT[HitNo]);
			HitEffectPos[HitNo][5].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x - 13, HitEffectT[HitNo]);
			HitEffectPos[HitNo][6].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x - 44, HitEffectT[HitNo]);
			HitEffectPos[HitNo][7].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x - 5, HitEffectT[HitNo]);
			HitEffectPos[HitNo][8].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x - 9, HitEffectT[HitNo]);
			HitEffectPos[HitNo][9].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x - 31, HitEffectT[HitNo]);

			HitEffectPos[HitNo][10].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x + 0, HitEffectT[HitNo]);
			HitEffectPos[HitNo][11].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x + 22, HitEffectT[HitNo]);
			HitEffectPos[HitNo][12].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x + 18, HitEffectT[HitNo]);
			HitEffectPos[HitNo][13].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x + 31, HitEffectT[HitNo]);
			HitEffectPos[HitNo][14].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x + 53, HitEffectT[HitNo]);
			HitEffectPos[HitNo][15].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x + 13, HitEffectT[HitNo]);
			HitEffectPos[HitNo][16].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x + 44, HitEffectT[HitNo]);
			HitEffectPos[HitNo][17].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x + 5, HitEffectT[HitNo]);
			HitEffectPos[HitNo][18].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x + 9, HitEffectT[HitNo]);
			HitEffectPos[HitNo][19].x = EaseOut(HitPos[Suit::CLUB][HitNo].x, HitEffectPos[Suit::CLUB][HitNo].x + 31, HitEffectT[HitNo]);

			HitEffectPos[HitNo][0].y = EaseOut(HitPos[Suit::CLUB][HitNo].y, HitEffectPos[Suit::CLUB][HitNo].y - 0, HitEffectT[HitNo]);
			HitEffectPos[HitNo][1].y = EaseOut(HitPos[Suit::CLUB][HitNo].y, HitEffectPos[Suit::CLUB][HitNo].y - 22, HitEffectT[HitNo]);
			HitEffectPos[HitNo][2].y = EaseOut(HitPos[Suit::CLUB][HitNo].y, HitEffectPos[Suit::CLUB][HitNo].y - 18, HitEffectT[HitNo]);
			HitEffectPos[HitNo][3].y = EaseOut(HitPos[Suit::CLUB][HitNo].y, HitEffectPos[Suit::CLUB][HitNo].y - 31, HitEffectT[HitNo]);
			HitEffectPos[HitNo][4].y = EaseOut(HitPos[Suit::CLUB][HitNo].y, HitEffectPos[Suit::CLUB][HitNo].y - 53, HitEffectT[HitNo]);
			HitEffectPos[HitNo][5].y = EaseOut(HitPos[Suit::CLUB][HitNo].y, HitEffectPos[Suit::CLUB][HitNo].y - 13, HitEffectT[HitNo]);
			HitEffectPos[HitNo][6].y = EaseOut(HitPos[Suit::CLUB][HitNo].y, HitEffectPos[Suit::CLUB][HitNo].y - 44, HitEffectT[HitNo]);
			HitEffectPos[HitNo][7].y = EaseOut(HitPos[Suit::CLUB][HitNo].y, HitEffectPos[Suit::CLUB][HitNo].y - 5, HitEffectT[HitNo]);
			HitEffectPos[HitNo][8].y = EaseOut(HitPos[Suit::CLUB][HitNo].y, HitEffectPos[Suit::CLUB][HitNo].y - 9, HitEffectT[HitNo]);
			HitEffectPos[HitNo][9].y = EaseOut(HitPos[Suit::CLUB][HitNo].y, HitEffectPos[Suit::CLUB][HitNo].y - 31, HitEffectT[HitNo]);

			for (int i = 0; i < 10; i++) {
				HitEffectPos[HitNo][i + 10].y = HitEffectPos[HitNo][i].y;
			}

		}



	


}

void Bullet::SetPlayerPos(Vector2 playerpos_){
	playerPos = playerpos_;
}