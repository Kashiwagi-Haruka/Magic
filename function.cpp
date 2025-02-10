#include <Vector2.h>
#include <assert.h>
#include "function.h"


Matrix3x3  Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2) {
	return {

		 matrix1.m[0][0] * matrix2.m[0][0] + matrix1.m[0][1] * matrix2.m[1][0] + matrix1.m[0][2] * matrix2.m[2][0],

		 matrix1.m[0][0] * matrix2.m[0][1] + matrix1.m[0][1] * matrix2.m[1][1] + matrix1.m[0][2] * matrix2.m[2][1],

		matrix1.m[0][0] * matrix2.m[0][2] + matrix1.m[0][1] * matrix2.m[1][2] + matrix1.m[0][2] * matrix2.m[2][2],


		 matrix1.m[1][0] * matrix2.m[0][0] + matrix1.m[1][1] * matrix2.m[1][0] + matrix1.m[1][2] * matrix2.m[2][0],

		 matrix1.m[1][0] * matrix2.m[0][1] + matrix1.m[1][1] * matrix2.m[1][1] + matrix1.m[1][2] * matrix2.m[2][1],

		  matrix1.m[1][0] * matrix2.m[0][2] + matrix1.m[1][1] * matrix2.m[1][2] + matrix1.m[1][2] * matrix2.m[2][2],


		 matrix1.m[2][0] * matrix2.m[0][0] + matrix1.m[2][1] * matrix2.m[1][0] + matrix1.m[2][2] * matrix2.m[2][0],

		 matrix1.m[2][0] * matrix2.m[0][1] + matrix1.m[2][1] * matrix2.m[1][1] + matrix1.m[2][2] * matrix2.m[2][1],

		  matrix1.m[2][0] * matrix2.m[0][2] + matrix1.m[2][1] * matrix2.m[1][2] + matrix1.m[2][2] * matrix2.m[2][2],

	};

}
Vector2 Multiply(Vector2 vector, Matrix3x3 matrix) {
	return {

	vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0],
	vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1]


	};

}



Matrix3x3 MakeRotateMatrix(float theta_) {
	Matrix3x3 result{};
	result.m[0][0] = cosf(theta_);
	result.m[0][1] = sinf(theta_);
	result.m[0][2] = 0;

	result.m[1][0] = -sinf(theta_);
	result.m[1][1] = cosf(theta_);
	result.m[1][2] = 0;

	result.m[2][0] = 0;
	result.m[2][1] = 0;
	result.m[2][2] = 1;


	return result;
}

Matrix3x3 MakeSceleMatrix(Vector2 scale_) {

	return {
		scale_.x,scale_.x,0,
		scale_.y,scale_.y,0,
		0,0,1
	};
}

Matrix3x3 MakeTranslateMatrix(Vector2 translate) {
	Matrix3x3 result{};
	result.m[0][0] = 1;
	result.m[0][1] = 0;
	result.m[0][2] = 0;

	result.m[1][0] = 0;
	result.m[1][1] = 1;
	result.m[1][2] = 0;

	result.m[2][0] = 0 + translate.x;
	result.m[2][1] = 0 + translate.y;
	result.m[2][2] = 1;


	return result;




}

Vector2 Transform(Vector2 vector, Matrix3x3 matrix) {

	Vector2 result{};

	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + 1.0f * matrix.m[2][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + 1.0f * matrix.m[2][1];

	/*result.x = result.x + 400;
	result.y = (result.y - 500) * -1;*/

	float w = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + 1.0f * matrix.m[2][2];
	assert(w != 0.0f);
	w;

	return result;



}

Matrix3x3 MakeafinMatrix(Vector2 scale_, float rotate, Vector2 trancerate) {
	Matrix3x3 result = { 0 };
	result.m[0][0] = scale_.x * cosf(rotate);
	result.m[0][1] = scale_.x * sinf(rotate);

	result.m[1][0] = scale_.y * -sinf(rotate);
	result.m[1][1] = scale_.y * cosf(rotate);

	result.m[2][0] = trancerate.x;
	result.m[2][1] =(trancerate.y);
	result.m[2][2] = 1;

	return  result;

}

Matrix3x3 Inverse(Matrix3x3 matrix){
	Matrix3x3 result{};
	float A = ((matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2]) + (matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0]) + (matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1])
		- (matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0]) - (matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2]) - (matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1])
		);
	return{
		result.m[0][0] = (1 / A) * (matrix.m[1][1] * matrix.m[2][2]) - (matrix.m[1][2] * matrix.m[2][1])	,	result.m[0][1] = (1 / A) * (-1 * (matrix.m[0][1] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][1]))	,	result.m[0][2] = (1 / A) * matrix.m[0][1] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][1],
		result.m[1][0] = (1 / A) * -(matrix.m[1][0] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][0]),	result.m[1][1] = (1 / A) * matrix.m[0][0] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][0]	,	result.m[1][2] = (1 / A) * -(matrix.m[0][0] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][0]),
		result.m[2][0] = (1 / A) * (matrix.m[1][0] * matrix.m[2][1] - matrix.m[1][1] * matrix.m[2][0]),	result.m[2][1] = (1 / A) * -(matrix.m[0][0] * matrix.m[2][1] - matrix.m[0][1] * matrix.m[2][0])	,	result.m[2][2] = (1 / A) * (matrix.m[0][0] * matrix.m[1][1] - matrix.m[0][1] * matrix.m[1][0])
	};

}
Matrix3x3 Transpose(Matrix3x3 matrix) {
	return {
		matrix.m[0][0],matrix.m[1][0],matrix.m[2][0],
		matrix.m[0][1],matrix.m[1][1],matrix.m[2][1],
		matrix.m[0][2],matrix.m[1][2],matrix.m[2][2]
	};


}

Matrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom) {
	Matrix3x3 result{};

	result.m[0][0] = 2.0f / (right - left);			result.m[0][1] = 0.0f;					result.m[0][2] = 0.0f;
	result.m[1][0] = 0.0f;					result.m[1][1] = 2.0f / (top - bottom);			result.m[1][2] = 0.0f;
	result.m[2][0] = (left + right) / (left - right); result.m[2][1] = (top + bottom) / (bottom - top); result.m[2][2] = 1.0f;

	return{
		result.m[0][0],result.m[0][1],result.m[0][2],
		result.m[1][0],result.m[1][1],result.m[1][2],
		result.m[2][0],result.m[2][1],result.m[2][2]
	};

}



Matrix3x3 MakeViewportMatrix(float left, float top, float width, float height) {
	Matrix3x3 result{};
	result.m[0][0] = width / 2.0f;			result.m[0][1] = 0.0f;					result.m[0][2] = 0.0f;
	result.m[1][0] = 0.0f;					result.m[1][1] = -(height / 2);			result.m[1][2] = 0.0f;
	result.m[2][0] = left + (width / 2.0f); result.m[2][1] = top + (height / 2.0f); result.m[2][2] = 1.0f;
	return{
		result.m[0][0],result.m[0][1],result.m[0][2],
		result.m[1][0],result.m[1][1],result.m[1][2],
		result.m[2][0],result.m[2][1],result.m[2][2]
	};

}

float NomalForce(float mass, Vector2 Gravity) {

	return -mass * Gravity.y;
}


float frictionalForce(float miu,Vector2 Gravity,float mass,Vector2 velocity) {

	float magnitude = miu * NomalForce(mass, Gravity);

	float direction;
	
	if (velocity.y < 0) {
		direction = -1;
	} else{
		direction = 1;
	} 
	
	float acceleration = magnitude * direction;

	acceleration /= mass;

	if (fabs(acceleration / 60.0f) > fabs(velocity.y)) {

		acceleration = velocity.y * 60.0f;
	}

	

	return acceleration;
		
}


float EaseOut(float pos1, float pos2, float t) {

	float easedT = 1.0f - powf(1.0f - t, 3.0f);


	return { (1.0f - easedT) * pos1 + easedT * pos2 };

}

float EaseInOut(float pos1, float pos2, float t) {

	float easedT;

	easedT = -(cosf(float(M_PI) * t) - 1.0f) / 2.0f;

	return { (1.0f - easedT) * pos1 + easedT * pos2 };
}

int EaseInOutInt(int x1, float x2, float t) {

	float easdT;

	easdT = -(cosf(float(M_PI) * t) - 1.0f) / 2.0f;

	return { int((1.0f - easdT) * x1 + easdT * x2) };
}

//Matrix3x3 MakewvpVpMatrix(Matrix3x3 worldMatrix, Vector2 worldSpacePos, LRTB Ortho, Vector2 ViewPortLT,Vector2 ViewPortWH) {
//	Matrix3x3 camera{1,0,0,
//					0,1,0,
//			worldSpacePos.x,worldSpacePos.y,1
//	};
//	Matrix3x3 view = Inverse(camera);
//	Matrix3x3 ortho{ 2.0f / (Ortho.RightButtom.x - Ortho.LeftTop.x),0.0f,0.0f,
//	0.0f,2.0f / (Ortho.LeftTop.y - Ortho.RightButtom.y),0.0f,
//		(Ortho.LeftTop.x + Ortho.RightButtom.x) / (Ortho.LeftTop.x - Ortho.RightButtom.x),(Ortho.LeftTop.y + Ortho.RightButtom.y) / (Ortho.RightButtom.y - Ortho.LeftTop.y),1.0f
//	};
//
//
//
//
//	Matrix3x3 viewPort{
//	ViewPortWH.x / 2.0f,0.0f,0.0f,
//	0.0f,-(ViewPortWH.y / 2.0f),0.0f,
//	ViewPortLT.x+(ViewPortWH.x/2.0f),ViewPortLT.y+(ViewPortWH.y/2.0f)
//	};
//
//	Matrix3x3 result{};
//
//	
//
//
//
//
//	result = Multiply(worldMatrix, view);
//	result = Multiply(result, ortho);
//	result = Multiply(result, view);
//
//
//
//	return result;
//
//}





