#pragma once
#include "function.h"
class Camera
{

private:

	Matrix3x3 cameraMatrix;
	Matrix3x3 viewMatrix;
	Matrix3x3 orthoMatrix;
	Matrix3x3 viewportMatrix;

	Vector2 scale_;
	float angle_;
	Vector2 translate_;


public:

	Camera();
	

	Matrix3x3 GetwvpVpMatrix();

	void UPDATECa();
	void SetScale(Vector2 scale);
	void SetAngle(float angle);
	void SetTranslate(Vector2 translate);

};

