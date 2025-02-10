#pragma once
#define _USE_MATH_DEFINES
#include <cstdlib>
#include <time.h>
#include <Vector2.h>
#include "Matrix3x3.h"
#include <Novice.h>


Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2);
Vector2 Multiply(Vector2 vector, Matrix3x3);
Matrix3x3 MakeRotateMatrix(float theta_);
Matrix3x3 MakeSceleMatrix(Vector2 scale_);


Matrix3x3 MakeTranslateMatrix(Vector2 trancelate);
Vector2 Transform(Vector2 vector, Matrix3x3 matrix);

Matrix3x3 MakeafinMatrix(Vector2 scale_, float rotate, Vector2 trancerate);


Matrix3x3 Inverse(Matrix3x3 matrix);//3x3逆行列の生成
Matrix3x3 Transpose(Matrix3x3 matrix);//3x3転置行列の生成

Matrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom);



Matrix3x3 MakeViewportMatrix(float left, float top, float width, float height);

float frictionalForce(float miu, Vector2 Gravity, float mass, Vector2 velocity);



float EaseOut(float pos1, float pos2, float t);
float EaseInOut(float pos1, float pos2, float t);
int EaseInOutInt(int x1, float x2, float t);



/// <summary>
///　レンダリングパイプライン用行列 
/// </summary>
/// <param name="worldMatrix">3x3ワールド行列</param>
/// <param name="worldSpacePos">カメラ用ワールド空間座標</param>
/// <param name="Ortho">正射影行列用(LeftTop RightBottom)</param>
/// <param name="ViewPortLT">ビューポートの座標</param>
/// <param name="ViewPortWH">ビューポートの幅</param>
//Matrix3x3 MakewvpVpMatrix(Matrix3x3 worldMatrix, Vector2 worldSpacePos, LRTB Ortho, Vector2 ViewPortLT, Vector2 ViewPortWH);
/// <returns></returns>