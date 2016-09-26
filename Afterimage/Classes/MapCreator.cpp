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

	for (int i = 0; i < allShops.size();i++)
	
	{
		log("shopPositionX=[%f]", allShops.at(i)->shopStatus.gate);

	}



	scheduleUpdate();

	return true;
};

void MapCreator::update(float delta)
{
	BackGroundMove();
}
//テキスト読み込み型
int MapCreator::createStage(int number)
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

	String* filename = String::createWithFormat("Stage/StageData_001.txt", number);

	string fileText = FileUtils::getInstance()->getStringFromFile(filename->getCString());
	vector<string> lines = split(fileText, '\n');

	int counter = 1;

	for (int i = number * 5; i < number * 5 + 5; i++)
	{
		vector<string> blocks = split(lines[i], ',');

		if (i != number * 5) {
			for (int j = 0; j < blocks.size(); j++)
			{
				int CSVnumber = atoi(blocks.at(j).c_str());
				if (i == number * 5 + 4) 
				{
					goalPosition = allShops.at(CSVnumber)->shopStatus.gate;

					break;
				}
				String* name = String::createWithFormat(pngName[counter].data(), CSVnumber);
				Sprite* spItem = Sprite::create(name->getCString());
				spItem->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
				spItem->setPosition(Vec2(SHOP_INTERVAL * j, heighter[counter]));
				if (i == number * 5 + 1)
					Floors->addChild(spItem);
				if (i == number * 5 + 2)
				{
					ShopBase* shop = ShopBase::create(CSVnumber);
					shop->initWithFile(name->getCString());
					shop->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
					shop->setPosition(Vec2(SHOP_INTERVAL * j, heighter[counter]));
					shop->shopStatus.gate += SHOP_INTERVAL*j;
					Shops->addChild(shop);
					if(shop->shopStatus.status==true)
					allShops.pushBack(shop);
					endPosition = SHOP_INTERVAL*blocks.size();
				}
				if (i == number * 5 + 3) 
					BackGrounds->addChild(spItem);
					
			}
			counter++;
		}
	}

	return 0;
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

	BackGrounds->setPositionX(XX/10);
}