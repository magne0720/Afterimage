#include "MapCreator.h"
#include "GameLayer.h"

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
	
	scheduleUpdate();

	return true;
};

void MapCreator::update(float delta)
{
	log("map->%f", MovementPosition);
	BuildingMove();
}
//テキスト読み込み型
int MapCreator::createStage(int number)
{
//	log("createStage_open");
//
////	std::ifstream ifs("GameStage_1.txt");
//	String* str;
//	//if (ifs.fail())
//	{
//		log("fail");
//		//std::cerr << "失敗" << std::endl;
//		//return 0;
//	}
////	else
//	{
//		//getline(ifs, str);
//		log("filename=[%s]", str);
//		log("end");
//	}
//	for (int i = 0; i != 12; i++) {
//		char split[12];
//
//		/*	std::cout << "[" << str[i] << "]" << std::endl;
//		String* name = String::createWithFormat("building_%d.png", str[i]);
//		Sprite* a = Sprite::create(name->getCString());
//		addChild(a);
//		*/
//	}
	return 0;
};

//直打ち型
int MapCreator::createStageTest(int number)
{
	int Floor[] = { 1,1,1,1,1,1,1,1,1,1,1,-1 };
	int Build[] = { 8,9,0,1,2,3,0,0,0,0,0,-1 };
	int BuildCheck[] = { 5,5,5,5,5,5,5,5,5,5,5,-1 };
	int *Process[] = {Floor,Build,BuildCheck};
	int pNum = 0;
	Vector<Sprite*> s[] = { Umbrellas,Gimmicks };	 
	float heighter[] = { 
		SHOP_HEIGHT,
		FLOOR_HEIGHT,
		SHOP_HEIGHT
	};

	endPosition = SHOP_INTERVAL*(sizeof(Floor)/sizeof(Floor[0])-sizeof(Floor[0]));
	log("endposition%d", endPosition);
	std::string pngName[] = { 
		"building_%d.png",
		"floor_%d.png",
		"building_%d.png" 
	};
	int *p = Process[0];
	for (int k = 0; k<3; k++)
	{
		p = Process[k];
		for (int i = 0; p[i] != -1; i++)
		{
			if (p[i] != 0) {
				String* name = String::createWithFormat(pngName[k].data(), p[i]);
				Sprite* spItem = Sprite::create(name->getCString());
				spItem->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
				spItem->setPosition(Vec2(SHOP_INTERVAL * i, heighter[k]));
				addChild(spItem);
				log("%s", name->getCString());

			}
		}
	}
	return 0;
}

//プレイヤーが今いる場所
int MapCreator::getPositionPlayerX(int positionX)
{
	return positionX;
}
//奥行別に動き替えるやつ
//レイヤー別のほうが楽だと思ったので保留
void MapCreator::BuildingMove()
{
	float XX = 0;

		XX =MovementPosition/endPosition;
		log("position=%f", XX);
		Floors->setPositionX(XX*(800));
}