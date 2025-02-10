#pragma once
#include <Novice.h>
class Handle
{


	


public:
	Handle();
	
	enum HandleNo {

		kPlayer = 0,
		kBullet,
		kEnemy,
		kTitle,
		kBackground,
		kResultNo,
		kResultBG,
		kKeys,
	};
	

	int GetHandle(HandleNo HandleNo);

	

private:
	
	int Handle_[8];
	

};

