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
	goMan = false;
	mobEnd = endPos;
	randomMan();
	walk(0);

	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> STime(100, 1000);
	this->schedule(schedule_selector(Umbrella::goManSwitch), ((float)STime(mt) / 100));


	
	this->scheduleUpdate();

	return true;
}

void Umbrella::randomMan()
{
	this->initWithFile("PlantNot1.png");

	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> mobSP(500, 1500);
	uniform_int_distribution<int> intRL(1, 2);
	mobspeed = (float)mobSP(mt) / 100;
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
	if (goMan == true)
	{
		switch (RL)
		{
		case 0:
			this->setPositionX(this->getPositionX());
			break;
		case 1:
			this->setPositionX(this->getPositionX() + mobspeed);
			if (this->getPositionX() > mobEnd)
			{
				randomMan();
			}
			break;
		case 2:
			this->setPositionX(this->getPositionX() - mobspeed);
			if (this->getPositionX() < designResolutionSize.width * -0.1f)
			{
				randomMan();
			}
			break;
		}
	}
}

void Umbrella::walk(float delta)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> randomTime(100, 200);
	uniform_int_distribution<int> RLranZERO(0, 2);
	RL = RLranZERO(mt);
	this->schedule(schedule_selector(Umbrella::walk), ((float)randomTime(mt)/100));
}

void Umbrella::goManSwitch(float delta)
{
	goMan = true;
}