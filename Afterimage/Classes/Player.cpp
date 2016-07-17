#include "Player.h"
bool Player::init()
{
	if (!Sprite::init())
	{
		return false;
	}


	return true;
}