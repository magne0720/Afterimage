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
	//log("%d", rainNum);



	return true;
}