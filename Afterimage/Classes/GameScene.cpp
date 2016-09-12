#include "GameScene.h"

bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	rainLayer = RainLayer::create(120);
	this->addChild(rainLayer, 0);

	gameLayer = GameLayer::create();
	this->addChild(gameLayer, 1);

	rainLayerb = RainLayer::create(260);
	this->addChild(rainLayerb,2);


	return true;
}