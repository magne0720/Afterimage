#include "GameScene.h"

bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	gameLayer = GameLayer::create();
	this->addChild(gameLayer, 0);



	return true;
}