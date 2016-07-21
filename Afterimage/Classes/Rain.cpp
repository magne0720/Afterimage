#include "Rain.h"

bool Rain::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	this->initWithFile("star.png");

	return true;
}