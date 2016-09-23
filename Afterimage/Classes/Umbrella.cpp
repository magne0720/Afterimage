#include "Umbrella.h"
#include "MultiResolution.h"

Umbrella *Umbrella::create(float endPos)
{

	Umbrella *pRet = new Umbrella();

	if (pRet && pRet->init(endPos))
	{
		pRet->autorelease();

		return pRet;
	}
	else {
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool Umbrella::init(float endPos)
{
	if (!Sprite::init())
	{
		return false;
	}

	mobEnd = endPos;
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
		this->setPosition(Vec2(mobEnd, designResolutionSize.height*0.3f));
	}
}

void Umbrella::update(float delta)
{
	if (RL == 1)
	{
		this->setPositionX(this->getPositionX() + mobspeed);
		if (this->getPositionX() > mobEnd)
		{
			randomMan();
		}
	}
	else
	{
		this->setPositionX(this->getPositionX() - mobspeed);
		if (this->getPositionX() < designResolutionSize.width * -0.1f)
		{
			randomMan();
		}

	}
}