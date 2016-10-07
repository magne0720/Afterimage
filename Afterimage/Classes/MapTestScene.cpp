#include "MapTestScene.h"

bool MapTestScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	MapCreater* creater = MapCreater::create(0);
	addChild(creater);


	return true;
};