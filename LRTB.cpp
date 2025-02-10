#include<Novice.h>

#include "LRTB.h"
void LRTBdrawQuad(LRTB pos, LRTB drawPos, int Handle, int color) {

	Novice::DrawQuad(
					int(pos.LeftTop.x), int(pos.LeftTop.y), int(pos.RightTop.x), int(pos.RightTop.y), 
					int(pos.LeftButtom.x), int(pos.LeftButtom.y), int(pos.RightButtom.x), int(pos.RightButtom.y),
					int(drawPos.LeftTop.x), int(drawPos.LeftTop.y), int(drawPos.RightButtom.x), int(drawPos.RightButtom.y), Handle, color);

}
