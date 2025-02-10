#include "Title.h"

Title::Title() {

	Handle_[0] = GetHandle(kTitle);
	Handle_[1] = GetHandle(ktitlestr);
	color = 0xffffffff;
}

void Title::TitleDraw() {

	Novice::DrawQuad(0, 0, 1280, 0, 0, 720, 1280, 720, 0, 0, 1280, 720, Handle_[0], color);

	Novice::DrawQuad(300, 50, 900, 50, 300, 400, 900, 400, 0, 0, 1280, 720, Handle_[1], color);


}