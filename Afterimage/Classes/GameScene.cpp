#include "GameScene.h"

bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	rainLayer = RainLayer::create(20);
	this->addChild(rainLayer, 0);

	gameLayer = GameLayer::create();
	this->addChild(gameLayer, 1);



	return true;
}