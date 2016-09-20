#include "Umbrella.h"
#include "MultiResolution.h"

bool Umbrella::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	randomMan();


	this->scheduleUpdate();

	return true;
}
void Umbrella::randomMan()
{
	this->initWithFile("PlantNot1.png");


	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> mobSP(5, 15);
	uniform_int_distribution<int> intRL(1, 2);
	mobspeed = (float)mobSP(mt);
	RL = intRL(mt);

	if (RL == 1)
	{
		this->setPosition(Vec2(designResolutionSize.width * -0.1f, designResolutionSize.height*0.3f));
	}
	else
	{
		this->setPosition(Vec2(designResolutionSize.width * 1, designResolutionSize.height*0.3f));
	}



}
void Umbrella::update(float delta)
{
	if (RL == 1)
	{
		this->setPositionX(this->getPositionX() + mobspeed);
	}
	else
	{
		this->setPositionX(this->getPositionX() - mobspeed);
	}


}