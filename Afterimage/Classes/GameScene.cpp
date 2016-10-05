#include "GameScene.h"

GameScene *GameScene::create(int fromTitle,int HP)

{

	GameScene *pRet = new GameScene();

	if (pRet && pRet->init(fromTitle,HP))
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

bool GameScene::init(int fromTitle,int HP)
{
	if (!Scene::init())
	{
		return false;
	}

	gameLayer = GameLayer::create(fromTitle,HP);
	this->addChild(gameLayer, 1);

	hpGauge = HPGauge::create(HP);
	this->addChild(hpGauge, 2);

	return true;
}