#include "RainManager.h"
#include "GameLayer.h"

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
	speed = 20.0f;
	delayTime = 2;
	this->scheduleUpdate();

	return true;
}
void RainManager::rainReset(Sprite *rain)
{
	float onceSp;
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> ranSP(100, 102);
	uniform_int_distribution<int> spCamera(spCameraMin, spCameraMax);

	onceSp = ranSP(mt) * 0.01f;
	rain->setPosition(Vec2(spCamera(mt), designResolutionSize.height *onceSp));
}
void RainManager::dropCreate()
{

	Rain* s_rain = Rain::create();
	rainReset(s_rain);
	this->addChild(s_rain);
	rain.pushBack(s_rain);
}
void RainManager::update(float delta)
{
	delayTime--;
	if (rain.size() <= rainOfRain)
	{
		if (delayTime < 0)
		{
			delayTime =1;
			dropCreate();
			//log("%d", rain.size());
		}
	}
	for (int i = 0; i < rain.size(); i++)
	{
		/*if (i == 50)
			rainOfRain = 400;
		if (i == 350)
			rainOfRain = 30;
		log("%d", i);*/

		rain.at(i)->setPositionY(rain.at(i)->getPositionY() - rain.at(i)->speed);
		if (rain.at(i)->getPositionY() < designResolutionSize.height * 0.0 + 200)
		{
			if (rain.size() <= rainOfRain)
			{
				rainReset(rain.at(i));
			}
			else
			{
				rain.at(i)->removeFromParentAndCleanup(true);
				rain.erase(i);
			}

			//rainReset(rain.at(i));
		}
	}
}

void RainManager::spCameraPos(float pos)
{
	spCameraMin = (int)pos - (int)designResolutionSize.width*1;
	spCameraMax = (int)pos + (int)designResolutionSize.width*1;
	log("%d,%d", spCameraMin,spCameraMax);

}