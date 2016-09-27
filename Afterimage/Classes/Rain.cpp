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
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> rainSpeed(18, 23);
	speed = rainSpeed(mt);


	return true;
}