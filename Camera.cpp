#include "Camera.h"

Camera::Camera() {

	scale_ = { 1.0f,1.0f };
	angle_ = 0.0f;
	translate_ = { 639.0f,250.0f };

	cameraMatrix = MakeafinMatrix(scale_, angle_, translate_);
	viewMatrix = Inverse(cameraMatrix);
	orthoMatrix = MakeOrthographicMatrix(-640.0f, 360.0f, 640.0f, -360.0f);
	viewportMatrix = MakeViewportMatrix(0, 0, 1280.0f, 720.0f);

}

void Camera::UPDATECa() {

	cameraMatrix = MakeafinMatrix(scale_, angle_, translate_);
	viewMatrix = Inverse(cameraMatrix);
	


}

Matrix3x3 Camera::GetwvpVpMatrix() {
	Matrix3x3 m;

	m=Multiply(viewMatrix, orthoMatrix);
	m= Multiply(m, viewportMatrix);

	return m;

}

void Camera::SetScale(Vector2 scale) {
	
	scale_ = scale;
	
}
void Camera::SetAngle(float angle) {

	angle_ = angle;

}
void Camera::SetTranslate(Vector2 translate) {

	translate_ = translate;

}