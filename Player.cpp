#include "Player.h"

Player::Player() {

	HP = 5;
	Hitsize = { 150.0f,225.0f };
	speed = 5;
	animation = Player::Enum::kWait;
	MiddlePos = {};
	handle[0] = GetHandle(kPlayer);
	handle[1] = GetHandle(kHP);
	t = 0;
	color = 0xffffffff;

	Angle = 0;
	drawPos = { {330,160}, {}, {} ,{624,965} };
	pos= { {0,Hitsize.y},{Hitsize},{0,0,},{Hitsize.x,0} };
	ScreenPos = {};
	bullet.Init();
	
	damageTime = 0;
	isDamage = false;

	wvpVpMatrix = {};

	vector = {};
	NEW = {};
	lengthP = {};
	isDead = false;

	for (int i = 0; i < 5; i++) {
		HPpos[i] = { {0.0f + i * 105,0},{100.0f + i * 105,0},{0.0f + i * 105,100},{100.0f + i * 105,100} };
		HPdrawPos = { {0,0},{},{},{1280,1280} };
	}
}

void Player::PlAnimation(char* keys) {

	
	t++;
	
	if (animation == Player::Enum::kWait) {
		drawPos = { {330,160}, {}, {} ,{624,965} };
	}

	if (animation == Player::Enum::kMove) {
		if (t == 7) {
			drawPos.LeftTop.x += 630;
			t = 0;
		}
		if (drawPos.LeftTop.x >= 624 * 4 + 330) {
			animation = Player::Enum::kMove2;
		}
	}
	if (animation == Player::Enum::kMove2) {
		if (t == 7) {
			drawPos.LeftTop.x -= 630;
			t = 0;
		}
		if (drawPos.LeftTop.x <= 330) {
			if (keys[DIK_SPACE]) {
				animation = Player::Enum::kMove;
			} else {
				animation = Player::Enum::kWait;
			}
			
		}
	}
	
	

	
	
	

	

	
}

void Player::PlMove(char* keys, char* preKeys) {

	handle[0] = GetHandle(kPlayer);

	/*bonePos[Enum::Bonepos::kArmLeft_LowerTop] = bonePos[Enum::Bonepos::kArmLeft_UpperBottom];
	bonePos[Enum::Bonepos::kArmRight_LowerTop]= bonePos[Enum::Bonepos::kArmRight_UpperBottom];
	bonePos[Enum::Bonepos::kArmLeft_LowerBottom] = bonePos[Enum::Bonepos::kHandLeft];
	bonePos[Enum::Bonepos::kArmRight_LowerBottom] = bonePos[Enum::Bonepos::kHandRight];

	bonePos[Enum::Bonepos::kKneesLeftTop] = bonePos[Enum::Bonepos::kThighsLeftBottom];
	bonePos[Enum::Bonepos::kKneesRightTop] = bonePos[Enum::Bonepos::kThighsRightBottom];
	bonePos[Enum::Bonepos::kKneesLeftBottom] = bonePos[Enum::Bonepos::kFeetLeft];
	bonePos[Enum::Bonepos::kKneesRightBottom] = bonePos[Enum::Bonepos::kFeetRight];*/

	wvpVpMatrix = GetwvpVpMatrix();

	if (keys[DIK_W] || keys[DIK_UP]) {
		vector.y = 1;
	}
	if (keys[DIK_S] || keys[DIK_DOWN]) {
		vector.y = -1;
	}
	if (keys[DIK_A] || keys[DIK_LEFT]) {
		vector.x = -1;
	}
	if (keys[DIK_D] || keys[DIK_RIGHT]) {
		vector.x = 1;
	}

	if ((keys[DIK_W] && keys[DIK_S]) || (!keys[DIK_W] && !keys[DIK_S]&&!keys[DIK_UP] && !keys[DIK_DOWN]) || (keys[DIK_UP] && keys[DIK_DOWN])|| (keys[DIK_W] && keys[DIK_DOWN]) || (keys[DIK_UP] && keys[DIK_S])) {
		vector.y = 0;
	}
	if ((keys[DIK_A] && keys[DIK_D]) || (!keys[DIK_A] && !keys[DIK_D] && !keys[DIK_LEFT] && !keys[DIK_RIGHT]) || (keys[DIK_LEFT] && keys[DIK_RIGHT]) || (keys[DIK_A] && keys[DIK_RIGHT]) || (keys[DIK_LEFT] && keys[DIK_D])) {
		vector.x = 0;
	}

	if (keys[DIK_SPACE]&&!preKeys[DIK_SPACE]) {
		t = 0;
		animation = Enum::kMove;
	}

	if (lengthP != 0.0f) {
		NEW.x = vector.x / lengthP;
		NEW.y = vector.y / lengthP;
	}
	lengthP = sqrtf(vector.x * vector.x + vector.y * vector.y);

	pos.LeftTop.x = pos.LeftTop.x + NEW.x * speed;
	pos.LeftButtom.x = pos.LeftButtom.x + NEW.x * speed;
	pos.RightTop.x = pos.RightTop.x + NEW.x * speed;
	pos.RightButtom.x = pos.RightButtom.x + NEW.x * speed;
	
	pos.LeftTop.y = pos.LeftTop.y + NEW.y * speed;
	pos.LeftButtom.y = pos.LeftButtom.y + NEW.y * speed;
	pos.RightTop.y = pos.RightTop.y + NEW.y * speed;
	pos.RightButtom.y = pos.RightButtom.y + NEW.y * speed;



	if (isDamage) {
		color = 0xff0000ff;
		damageTime++;
	} else {
		damageTime = 0;
		color = 0xffffffff;
	}
	if (damageTime >= 60) {
		isDamage = false;
	}
	
	
	if (HP <= 0) {
		isDead = true;
	}

	ScreenPos.LeftTop = Transform(pos.LeftTop, wvpVpMatrix);
	ScreenPos.RightTop = Transform(pos.RightTop, wvpVpMatrix);
	ScreenPos.LeftButtom = Transform(pos.LeftButtom, wvpVpMatrix);
	ScreenPos.RightButtom = Transform(pos.RightButtom, wvpVpMatrix);
	
	
	MiddlePos = MakeMiddlePos();
	bullet.SetPlayerPos(MiddlePos);
	bullet.Move(keys,preKeys);

	

}

void Player::PlDraw() {
	
	bullet.Draw();

	

	LRTBdrawQuad(ScreenPos, drawPos, handle[0], color);
	for (int i = 0; i < HP; i++) {
		LRTBdrawQuad(HPpos[i], HPdrawPos, handle[1], 0xffffffff);
	}

}



Vector2 Player::MakeMiddlePos() {

	
	return { (pos.LeftTop.x + pos.RightTop.x) / 2.0f,(pos.LeftTop.y + pos.RightButtom.y) / 2.0f };

}
LRTB Player::SetBodyAngle(LRTB posP, Vector2 BoneTopPos, Vector2 BoneBottomPos) {
	LRTB result{};
	Vector2 origin = { (posP.LeftButtom.x + posP.RightButtom.x)/2.0f,(posP.LeftButtom.y + posP.LeftButtom.y)/2.0f };
	Vector2 New{};
	float Length{};
	
	Length = sqrtf(powf(BoneTopPos.x - BoneBottomPos.x, 2.0f) + powf(BoneTopPos.y - BoneBottomPos.y, 2.0f));

	New = { Angle,fabsf(1.0f - Angle) };


	result.LeftButtom.x = New.x * Length;
	result.RightButtom.x = New.x * Length;

	result.LeftButtom.y = New.y * Length;
	result.RightButtom.y = New.y * Length;
	
	return result;

	
}

void Player::SetIsDamage(bool isdamage) {

	
	isDamage = isdamage;

}
void Player::SetHP(int hp) {

	HP += hp;

}

void Player::Reset() {
	HP = 5;
	Hitsize = { 150.0f,225.0f };
	speed = 5;
	animation = Player::Enum::kWait;
	MiddlePos = {};
	handle[0] = GetHandle(kPlayer);
	t = 0;
	color = 0xffffffff;

	Angle = 0;
	drawPos = { {330,160}, {}, {} ,{624,965} };
	pos = { {0,Hitsize.y},{Hitsize},{0,0,},{Hitsize.x,0} };
	ScreenPos = {};
	bullet.Init();

	damageTime = 0;
	isDamage = false;

	wvpVpMatrix = {};

	vector = {};
	NEW = {};
	lengthP = {};

	isDead = false;
}