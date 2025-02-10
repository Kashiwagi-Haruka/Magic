#pragma once
#include <Vector2.h>
#include "LRTB.h"
#include "Handle.h"
#include "function.h"
#include "Camera.h"
#include "Bullet.h"

class Player:Handle,Camera
{

private:
	

	Vector2 MiddlePos;
	
	Vector2 Hitsize;

	
	LRTB pos;
	LRTB ScreenPos;
	LRTB drawPos;
	

	int handle[2];
	int color;

	int t;

	Matrix3x3 wvpVpMatrix;

	float Angle;
	float speed;
	Vector2 NEW;
	float lengthP;
	Vector2 vector;

	bool isDamage;
	int damageTime;
	int HP;

	LRTB SetBodyAngle(LRTB pos, Vector2 BoneTopPos, Vector2 BoneBottomPos);


	struct Enum
	{
		enum Animation {

			kWait=0,
			kMove,
			kMove2,

		};

		enum Bonepos {

			kHead = 0,//頭

			kBodyTop,//体上
			kBodyBottom,//体下

			kArmLeft_UpperTop,//左上腕上
			kArmLeft_UpperBottom,//左上腕下
			kArmLeft_LowerTop,//左下腕上
			kArmLeft_LowerBottom,//左下腕下
			kHandLeft,//左手

			kArmRight_UpperTop,//右上腕上
			kArmRight_UpperBottom,//右上腕下
			kArmRight_LowerTop,//右下腕上
			kArmRight_LowerBottom,//右下腕下
			kHandRight,//右手

			kThighsLeftTop,//左太もも上
			kThighsLeftBottom,//左太もも下
			kKneesLeftTop,//左膝
			kKneesLeftBottom,//左膝
			kFeetLeft,//左足

			kThighsRightTop,//右太もも上
			kThighsRightBottom,//右太もも下
			kKneesRightTop,//右膝上
			kKneesRightBottom,//右膝下
			kFeetRight,//右足
		};
		enum Parts {
			kFaceLeft,//肌
			kFaceRight,//肌

			kBangsLeft,//前髪左
			kBangsRight,//前髪右
			kSidehairLeft,//横髪左
			kSidehairRight,//横髪右
			kBackhairLeft,//後髪左
			kBackhairRight, //後髪右

			kEyelidsLeft,//瞼左
			kEyelidsRight,//瞼右
			kEyeLeft,//瞳左
			kEyeRight,//瞳右

			kMouseLeft,//口
			kMouseRight,//口


			kClothesLeft,//服
			kClothesRight,//服
			kArmLeftUP,//腕
			kArmRightUP,//腕
			kArmLeftDOWN,//腕
			kArmRightDOWN,//腕
			kPantsLeftUP,//ズボン
			kPantsRightUP,//ズボン
			kPantsLeftDOWN,//ズボン
			kPantsRightDOWN,//ズボン
			kHat,//帽子


		};

	};
	
	bool isDead;
	
	LRTB HPpos[5];
	LRTB HPdrawPos;
	

	Enum::Animation animation;
	protected:

		Bullet bullet;

		Player();


		void PlMove(char* keys, char* preKeys);
		void PlDraw();
		void PlAnimation(char* keys);
		void SetIsDamage(bool isdamage);
		void SetHP(int HP);
		
		bool GetIsDamage() { return isDamage; };
		bool GetIsDead() { return isDead; };

		Vector2 MakeMiddlePos();
		Vector2 GetMiddlePos() {

			return MiddlePos;
		}
		Vector2 GetplSize() {
			return Hitsize;
		}

		void Reset();

};

