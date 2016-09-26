#include "StageScene.h"

bool StageScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	StageLayer = StageLayer::create();
	this->addChild(StageLayer);


	return true;
}