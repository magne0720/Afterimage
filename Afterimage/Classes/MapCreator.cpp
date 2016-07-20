#include "MapCreator.h"

MapCreator* MapCreator::create(int number)
{
	MapCreator *pRet = new MapCreator();
		if (pRet && pRet->init(number))
		{
		pRet->autorelease();
		return pRet;
		}
		else
		{
		delete pRet;
		pRet = nullptr;
		return nullptr;
		}
};

bool MapCreator::init(int number)
{
	if (!Layer::init())
	{
		return false;
	}
	log("Welcome To MapCreator");
	createStage(number);

	createStageTest(1);
	

	return true;
};

void MapCreator::update(float delta)
{





}
//ƒeƒLƒXƒg“Ç‚İ‚İŒ^
int MapCreator::createStage(int number)
{
	log("createStage_open");

	std::ifstream ifs("GameStage_1.txt");
	char str[256];
	if (ifs.fail())
	{
		log("fail");
		std::cerr << "¸”s" << std::endl;
		return -1;
	}
	while (ifs.getline(str, 256 - 1))
	{
		log("%c",str);
		std::cout << "[" << str << "]" << std::endl;
	}
	return 0;
};


int MapCreator::createStageTest(int number)
{
	int Build[] = { 0, 1, 2, 0, 0, -1 };
	int Floor[] = { 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 -1 };

	int *p = Build;
	for (int i = 0; p[i] != -1; i++)
	{
		String* name = String::createWithFormat("building_%d.png", p[i]);
		Sprite* spItem = Sprite::create(name->getCString());
		spItem->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		spItem->setPosition(Vec2(800 * i - 600, designResolutionSize.height*0.19f));
		addChild(spItem);
	}
	p = Floor;
	for (int i = 0; p[i] != -1; i++)
	{
		String* name = String::createWithFormat("floor_%d.png", p[i]);
		Sprite* spItem = Sprite::create(name->getCString());
		spItem->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		spItem->setPosition(Vec2(100 * i , designResolutionSize.height*0.0f));
		addChild(spItem);
	}


	return 0;
}

Sprite* MapCreator::createObjectFloor(int number)
{
	log("createObjectFloor");
	String* name = String::createWithFormat("Floor_%d.png", number);
	Sprite* sp = Sprite::create(name->getCString());

	return sp;
};

Sprite* MapCreator::createObjectBuilding(int number)
{
	log("createObjectBuilding");
	String* name = String::createWithFormat("building_%d.png", number);
	Sprite* sp = Sprite::create(name->getCString());

	return sp;
};

Sprite* MapCreator::createObjectUmbrella(int number)
{
	log("createObjectUmbrella");
	String* name = String::createWithFormat("umbrella%d.png", number);
	Sprite* sp = Sprite::create(name->getCString());
	addChild(sp);

	return sp;
};

Sprite* MapCreator::createObjectGimmick(int number)
{
	log("createObjectGimmick");
	String* name = String::createWithFormat("gimmick%d.png", number);
	Sprite* sp = Sprite::create(name->getCString());
	addChild(sp);

	return sp;
};
