#include "Handle.h"

Handle::Handle() {

	Handle_[kPlayer] = Novice::LoadTexture("./Resources/Player.png");
	Handle_[kTitle] = Novice::LoadTexture("./Resources/Title.png");
	Handle_[kEnemy] = Novice::LoadTexture("./Resources/Enemy.png");
	Handle_[kBackground] = Novice::LoadTexture("./Resources/Background.png");
	Handle_[kResultNo]= Novice::LoadTexture("./Resources/string.png");
	Handle_[kKeys]=Novice::LoadTexture("./Resources/keys.png");
}

int Handle::GetHandle(HandleNo HandleNo) {

	return { Handle_[HandleNo] };

}