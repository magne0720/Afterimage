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
//ÉeÉLÉXÉgì«Ç›çûÇ›å^
int MapCreator::createStage(int number)
{
	log("createStage_open");

	std::ifstream ifs("GameStage_1.txt");
	std::string str;
	if (ifs.fail())
	{
		log("fail");
		std::cerr << "é∏îs" << std::endl;
		return -1;
	}
	else
	{
		getline(ifs, str);
		log("filename=[%s]", str);
		log("end");
	}
	for (int i = 0; i != 12; i++) {
		char split[12];
		if (str.at(i) != ',') {
			split[i] = str.at(i);
		}

		/*	std::cout << "[" << str[i] << "]" << std::endl;
		String* name = String::createWithFormat("building_%d.png", str[i]);
		Sprite* a = Sprite::create(name->getCString());
		addChild(a);
		*/
	}
	return 0;
};

//íºë≈Çøå^
int MapCreator::createStageTest(int number)
{
	int Floor[] = { 0,0,0,0,0,0,0,0,0,0,-1 };
	int Build[] = { 0,1,0,0,1,0,0,0,-1 };
	int *MAP[] = { Floor,Build };
	
	float heighter[] = { FLOOR_HEIGHT,SHOP_HEIGHT };
	std::string pngName[] = { "floor_%d.png","building_%d.png" };

	int *p = MAP[0];
	for (int k = 0; k<2; k++)
	{
		p = MAP[k];
		for (int i = 0; p[i] != -1; i++)
		{
			String* name = String::createWithFormat(pngName[k].data(), p[i]);
			log("%s", name->getCString());
			Sprite* spItem = Sprite::create(name->getCString());
			spItem->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
			spItem->setPosition(Vec2(SHOP_INTERVAL * i, heighter[k]));
			addChild(spItem);
		}
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
