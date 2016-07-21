#include "RainManager.h"

RainManager *RainManager::create(int rainNum)

{
	RainManager *pRet = new RainManager();
	if (pRet && pRet->init(rainNum))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{

		delete pRet;

		pRet = NULL;

		return NULL;

	}
}
bool RainManager::init(int rainNum)
{
	if (!Node::init())
	{
		return false;
	}
	rainOfRain = rainNum;
	speed = 25.0f;
	for (int i = 0; i < rainOfRain; i++)
	{
		rain.push_back(Rain::create());
		rainReset(rain[i]);
		this->addChild(rain[i]);
	}
	this->scheduleUpdate();

	return true;
}
void RainManager::rainReset(Sprite *rain)
{
	float onceSp;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> ranSP(100, 200);
	onceSp = ranSP(mt) * 0.01f;
	rain->setPosition(Vec2(rand() % (int)designResolutionSize.width + 1, designResolutionSize.height * onceSp));
}
void RainManager::update(float delta)
{
	for (int i = 0; i < rainOfRain; i++)
	{
		rain[i]->setPositionY(rain[i]->getPositionY() - speed);
		if (rain[i]->getPositionY() < designResolutionSize.height*0.1f)
		{
			rainReset(rain[i]);
		}
	}
}