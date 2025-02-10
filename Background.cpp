#include "Background.h"

Background::Background() {

	handle = GetHandle(kBackground);
	Pos = { {0,0},{1280,0},{0,720},{1280,720} };
}
void Background::BgMove() {
	
	


}

void Background::BgDraw() {

	
	LRTBdrawQuad(Pos, {{0,0},{},{},{2560,1440}}, handle, 0xffffffff);

}
















