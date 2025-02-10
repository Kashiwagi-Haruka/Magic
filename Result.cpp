#include "Result.h"

Result::Result() {

	BGPos = { {0,0},{1280,0},{0,720},{1280,720} };
	handle[0] = GetHandle(kTitle);
	handle[1] = GetHandle(kResultNo);
	handle[2] = GetHandle(kStringetc);
	FirstNo = 0;
	SecondNo = 0;
	ThirdNo = 0;
	ForthNo = 0;
	FivethNo = 0;
}

void Result::ResultMove() {

	

	FirstNo = Score / 10000;
	SecondNo = Score / 1000 - FirstNo * 10;
	ThirdNo = Score / 100 - FirstNo * 100 - SecondNo * 10;
	ForthNo = Score / 10 - FirstNo * 1000 - SecondNo * 100-ThirdNo*10;
	FivethNo = Score- FirstNo * 10000 - SecondNo * 1000 - ThirdNo * 100 - ForthNo*10;
}
void Result::ResultNoDraw(int No,Vector2 pos) {

	for (int i = 0; i < 10; i++) {
		if (No == i) {
			drawPos = { {i * 600.0f,0},{},{},{600.0f,500.0f} };
		}
	}
	//Byouga
	

	LRTBdrawQuad({ {pos.x - 25,pos.y - 25,},{pos.x + 25,pos.y - 25},{pos.x - 25,pos.y + 25},{pos.x + 25,pos.y + 25} }, drawPos, handle[1], 0xffffffff);

}
void Result::ResultDraw() {

	LRTBdrawQuad(BGPos, { {0,0},{},{},{1280,720} }, handle[0], 0xffffffff);

	LRTBdrawQuad({ {440,75}, {840,75},{440,175},{840,175} }, { {500,0},{},{},{400,100} }, handle[2], 0xffffffff);
	LRTBdrawQuad({ {190,500}, {1090,500},{190,600},{1090,600} }, { {0,100},{},{},{900,100} }, handle[2], 0xffffffdd);

	ResultNoDraw(FirstNo,{540,200});
	ResultNoDraw(SecondNo, { 590,200 });
	ResultNoDraw(ThirdNo, { 640,200 });
	ResultNoDraw(ForthNo, { 690,200 });
	ResultNoDraw(FivethNo, { 740,200 });
}
void Result::SetScore(int scoreS) {


	Score = scoreS;

}