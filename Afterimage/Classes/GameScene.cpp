#include "GameScene.h"

bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	rainLayer = RainLayer::create(100);
	this->addChild(rainLayer, 0);

	gameLayer = GameLayer::create();
	this->addChild(gameLayer, 1);

	rainLayerb = RainLayer::create(50);
	this->addChild(rainLayerb,2);


	return true;
}