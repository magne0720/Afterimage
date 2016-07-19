#include "Player.h"
#include "MultiResolution.h"
bool Player::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	this->initWithFile("PlantNot1.png");
	this->setScale(0.3f);

	this->getBoundingBox();
	return true;
}