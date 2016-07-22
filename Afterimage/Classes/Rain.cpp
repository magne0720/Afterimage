#include "Rain.h"

bool Rain::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	initWithFile("rain.png");
	setColor(Color3B(220, 240, 250));
	setScale(0.3, 2.0);
	setOpacity(200);

	return true;
}