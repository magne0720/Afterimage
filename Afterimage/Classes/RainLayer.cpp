#include "RainLayer.h"

RainLayer *RainLayer::create(int rainNum)

{
	RainLayer *pRet = new RainLayer();
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
bool RainLayer::init(int rainNum)
{
	if (!Layer::init())
	{
		return false;
	}

	rainManager = RainManager::create(rainNum);
	this->addChild(rainManager);



	//log("%d", rainNum);
	return true;
}