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
	stockRL = 0;
	goMan = false;
	stopRandom = true;
	mobEnd = endPos;
	//randomMan();

	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> STime(100, 1000);
	this->schedule(schedule_selector(Umbrella::goManSwitch), ((float)STime(mt) / 100));
	this->scheduleOnce(schedule_selector(Umbrella::walk), ((float)STime(mt) / 100));



	
	this->scheduleUpdate();

	return true;
}

void Umbrella::randomMan()
{
	if (stopRandom == true)
	{
		this->initWithFile("PlantNot1.png");
		random_device rd;
		mt19937 mt(rd());
		uniform_int_distribution<int> mobSP(500, 1500);
		uniform_int_distribution<int> intRL(1, 2);
		mobspeed = (float)mobSP(mt) / 100;
		RL = intRL(mt);
		stockRL = RL;
		if (RL == 1)
		{
			this->setPosition(Vec2(designResolutionSize.width * -0.1f, designResolutionSize.height*0.3f));
		}
		else
		{
			this->setPosition(Vec2(mobEnd, designResolutionSize.height*0.3f));
		}
		stopRandomOFF();
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
			this->setFlipX(false);
			break;
		case 2:
			this->setPositionX(this->getPositionX() - mobspeed);
			this->setFlipX(true);
			break;
		}
		if (this->getPositionX() > mobEnd || this->getPositionX() < designResolutionSize.width * -0.1f)
		{
			randomMan();
		}


	}
}

void Umbrella::walk(float delta)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> randomTime(100, 300);
	uniform_int_distribution<int> RLranZ(0, 4);
	//if (RLranZ(mt) == 0)
	//{
	//	stockRL = RL;
	//	RL = 0;
	//	this->scheduleOnce(schedule_selector(Umbrella::leftRightMan), ((float)randomTime(mt) / 100));
	//}
	//else
	//{
	//	this->schedule(schedule_selector(Umbrella::walk), ((float)randomTime(mt) / 100));
	//}
	switch (RLranZ(mt))
	{
	case 0:
			stockRL = RL;
			RL = 0;
			this->scheduleOnce(schedule_selector(Umbrella::leftRightMan), ((float)randomTime(mt) / 100));
		break;
	case 1:
		stockRL = RL;
		RL = 0;
		this->scheduleOnce(schedule_selector(Umbrella::leftRightMan), ((float)randomTime(mt) / 100));
		break;
	default:

		//this->schedule(schedule_selector(Umbrella::walk), ((float)randomTime(mt) / 100));
		stockRL = RL;
		RL = 0;
		this->scheduleOnce(schedule_selector(Umbrella::leftRightMan), ((float)randomTime(mt) / 100));

		break;
	}
}

void Umbrella::goManSwitch(float delta)
{
	goMan = true;
}

void Umbrella::stopRandomOFF()
{
	stopRandom = false;
	this->schedule(schedule_selector(Umbrella::stopRandomON), 6);

}

void Umbrella::stopRandomON(float delta)
{
	stopRandom = true;
}

void Umbrella::leftRightMan(float delta)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> LRTime(500, 1000);
	RL = stockRL;
	this->scheduleOnce(schedule_selector(Umbrella::walk), ((float)LRTime(mt) / 100));

}