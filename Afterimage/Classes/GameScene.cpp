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

	//this->scheduleOnce(schedule_selector(GameScene::rainDelay), 0.5f);
	rainLayerb = RainLayer::create(260);
	this->addChild(rainLayerb, 2);

	return true;
}

void GameScene::rainDelay(float delta)
{
	rainLayerb = RainLayer::create(260);
	this->addChild(rainLayerb, 2);

}