#include "GameScene.h"

GameScene *GameScene::create(int fromTitle)

{

	GameScene *pRet = new GameScene();

	if (pRet && pRet->init(fromTitle))
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

bool GameScene::init(int fromTitle)
{
	if (!Scene::init())
	{
		return false;
	}

	rainLayer = RainLayer::create(120);
	this->addChild(rainLayer, 0);

	gameLayer = GameLayer::create(fromTitle);
	this->addChild(gameLayer, 1);

	rainLayerb = RainLayer::create(260);
	this->addChild(rainLayerb, 2);

	return true;
}