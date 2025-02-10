#include "Line.h"

Line::Line() {

	

	wvpVpMatrix = {};

	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 2; k++) {
			screenPos[i][k] = {};
		}
	}
		pos[0][0] = { -1280,0 };
		pos[0][1] = { 1280,0 };
		pos[1][0] = { 0,-720 };
		pos[1][1] = { 0,720 };
	

}

void Line::LiMove() {
	
	wvpVpMatrix = GetwvpVpMatrix();

	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 2; k++) {

			screenPos[i][k] = Transform(pos[i][k], wvpVpMatrix);


		}
	}
	

}

void Line::LiDraw() {

	
	Novice::DrawLine(static_cast<int>(screenPos[0][0].x), static_cast<int>(screenPos[0][0].y), static_cast<int>(screenPos[0][1].x), static_cast<int>(screenPos[0][1].y), 0x00ff00ff);
	Novice::DrawLine(static_cast<int>(screenPos[1][0].x), static_cast<int>(screenPos[1][0].y), static_cast<int>(screenPos[1][1].x), static_cast<int>(screenPos[1][1].y), 0xff0000ff);
}

