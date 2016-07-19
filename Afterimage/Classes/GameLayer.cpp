#include "GameLayer.h"

bool GameLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	player = Player::create();
	this->addChild(player, 2);



	return true;
}