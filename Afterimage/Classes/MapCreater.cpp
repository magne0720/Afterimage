#include "mapCreater.h"

MapCreater* MapCreater::create(int number)
{
	MapCreater *pRet = new MapCreater();
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

bool MapCreater::init(int number)
{
	if (!Layer::init())
	{
		return false;
	}
	log("Welcome To MapCreater");
	createStage(number);

	createStageTest(1);
	

	return true;
};

void MapCreater::update(float delta)
{





}
//ƒeƒLƒXƒg“Ç‚İ‚İŒ^
int MapCreater::createStage(int number)
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

int MapCreater::createStageTest(int number)
{
	int a[] = { 0,1,2,0,0,-1 };
	int *p=a;
	for (int i = 0; a[i] != -1; i++)
	{
		Sprite* a = createObjectBuilding(p[i]);
		a->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		a->setPosition(Vec2(800*i-600, designResolutionSize.height*0.19f));
		addChild(a);
	}


	return 0;
}

Sprite* MapCreater::createObjectBuilding(int number)
{
	log("createObjectBuilding");
	String* name = String::createWithFormat("building_%d.png", number);
	Sprite* sp = Sprite::create(name->getCString());
	
	return sp;
};

Sprite* MapCreater::createObjectUmbrella(int number)
{
	String* name = String::createWithFormat("umbrella%d.png", number);
	Sprite* sp = Sprite::create(name->getCString());
	addChild(sp);

	return sp;
};

Sprite* MapCreater::createObjectGimmick(int number)
{
	String* name = String::createWithFormat("gimmick%d.png", number);
	Sprite* sp = Sprite::create(name->getCString());
	addChild(sp);

	return sp;
};
