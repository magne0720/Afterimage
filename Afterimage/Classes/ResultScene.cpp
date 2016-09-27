#include "ResultScene.h"

ResultScene* ResultScene::create(int score) 
{

	ResultScene *pRet = new ResultScene();
	if (pRet && pRet->init(score))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool ResultScene::init(int score)
{
	if (!Scene::init())
	{
		return false;
	}

	ResultLayer* ResultLayer = ResultLayer::create(0);
	addChild(ResultLayer);


	return true;
}