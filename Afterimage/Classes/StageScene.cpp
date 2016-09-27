#include "StageScene.h"

bool StageScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	StageLayer* StageLayer = StageLayer::create();
	addChild(StageLayer);


	return true;
}