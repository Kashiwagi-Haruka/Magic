#include "Title.h"

Title::Title() {

	Handle_ = GetHandle(kTitle);
	color = 0xffffffff;
}

void Title::TitleDraw() {

	Novice::DrawQuad(0, 0, 1280, 0, 0, 720, 1280, 720, 0, 0, 1280, 720, Handle_, color);


}