#include "MapCreator.h"
#include "StageItem.h"

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
	startPosition = 0;
	endPosition = 0;

	Floors = Layer::create();
	addChild(Floors,4);

	BackGrounds = Layer::create();
	addChild(BackGrounds,2);

	Shops = Layer::create();
	addChild(Shops,3);

	StageItem* ss = StageItem::create(1);
	addChild(ss);

	createStage(number);

	scheduleUpdate();

	return true;
};

void MapCreator::update(float delta)
{
	BackGroundMove();
}
//テキスト読み込み型
void MapCreator::createStage(int number)
{
	auto split = [](const std::string& input, char delimiter)
	{
		istringstream stream(input);
		string field;
		vector<string> result;
		while (std::getline(stream, field, delimiter))
		{
			result.push_back(field);
		}
		return result;
	};
	float heighter[] = {
		0,
		FLOOR_HEIGHT,
		SHOP_HEIGHT,
		SHOP_HEIGHT
	};
	std::string pngName[] = {
		"none_%d.png",
		"floor_%d.png",
		"building_%d.png",
		"background_%d.png",
	};
	String* filename = String::createWithFormat("Stage/StageData.txt");

	string fileText = FileUtils::getInstance()->getStringFromFile(filename->getCString());
	vector<string> lines = split(fileText, '\n');			//行配列
	

	vector<string> datas = split(lines[number], '<');//ほしい行をデータにまとめて分ける

		//log("lines=[%s]", lines[i].c_str());
	for (int i = 0; i < datas.size();i++)
	{
		char data = datas[i][0];

		//log("data=[%c]", data);

		if (data == 'n')break;

		vector<string> blocks = split(datas[i], ',');//行配列

		switch (data)
		{
		case 'F'://FLOOR
		//	log("F");
			FloorCreate(blocks);
			break;
		case 'S'://SHOP
			StageCreate(blocks);
			//log("S");
			break;
		case 'B'://BACK
			BackCreate(blocks);
			//log("B");
			break;
		case 'G'://GOAL
			goalPosition = openShops.at(atoi(blocks[1].c_str()))->shopStatus.gate;
			//	log("goal=[%f]", goalPosition);
			break;
		default:
			//log("default");

			break;
		}
	}
};
//プレイヤーが今いる場所
float MapCreator::getPositionPlayerX(float positionX)
{
	playerPosition = positionX;
	//log("playerPosition==%f", playerPosition);

	return positionX;
}
//奥行別に動き替えるやつ
void MapCreator::BackGroundMove()
{
	float XX = (playerPosition);

	BackGrounds->setPositionX(XX/8);
}


void MapCreator::FloorCreate(vector<string> letter)
{
	//log("welcome To FloorCreate!");
	for (int i = 1; i < letter.size(); i++)
	{
		//log("[%d,%d]", i, letter.size());
		int CSVnumber = atoi(letter.at(i).c_str());
		String* name = String::createWithFormat("floor_%d.png", CSVnumber);
		Sprite* spItem = Sprite::create(name->getCString());
		spItem->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		spItem->setPosition(Vec2(SHOP_INTERVAL * (i-1), FLOOR_HEIGHT));
		Floors->addChild(spItem);
	}
};
void MapCreator::StageCreate(vector<string> letter)
{
	//log("welcome To StageCreate!"); 
	for (int i = 1; i < letter.size(); i++)
	{
		//log("%c", letter[i].c_str());
		int CSVnumber = atoi(letter[i].c_str());
		//log("CSVnumber=%d", CSVnumber);
		ShopBase* shop = ShopBase::create(CSVnumber,i-1);
		shop->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		shop->setPosition(Vec2(SHOP_INTERVAL * (i - 1), SHOP_HEIGHT));
		shop->shopStatus.gate += SHOP_INTERVAL * (i - 1);
		shop->shopStatus.min += SHOP_INTERVAL*(i - 1);
		shop->shopStatus.max += SHOP_INTERVAL*(i - 1);
		
		Shops->addChild(shop);
		if (shop->shopStatus.status == true)
			openShops.pushBack(shop);
		allShops.pushBack(shop);
		endPosition = SHOP_INTERVAL*letter.size();
	}
};

void MapCreator::BackCreate(vector<string> letter)
{
	//log("welcome To BackCreate!");
	for (int i = 1; i < letter.size(); i++)
	{
		int CSVnumber = atoi(letter.at(i).c_str());
		String* name = String::createWithFormat("background_%d.png", CSVnumber);
		Sprite* spItem = Sprite::create(name->getCString());
		spItem->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		spItem->setPosition(Vec2(SHOP_INTERVAL * (i - 1), SHOP_HEIGHT));
		BackGrounds->addChild(spItem);
	}
};

void MapCreator::previewStage()
{
	Shops->setPosition(Vec2(-goalPosition, designResolutionSize.height*0.3));
	BackGrounds->setPosition(Vec2(-goalPosition, designResolutionSize.height*0.3));
	Floors->setPosition(Vec2(-goalPosition, designResolutionSize.height*0.3));
};

void MapCreator::ressetStage()
{
	Shops->removeAllChildren();
	BackGrounds->removeAllChildren();
	Floors->removeAllChildren();
};