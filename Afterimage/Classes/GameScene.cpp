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

	gameLayer = GameLayer::create(fromTitle,0);
	this->addChild(gameLayer, 1);

	hpGauge = HPGauge::create();
	this->addChild(hpGauge, 2);

	return true;
}