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
//�e�L�X�g�ǂݍ��݌^
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
	int counter = number * 6;

	String* filename = String::createWithFormat("Stage/StageData_001.txt");

	string fileText = FileUtils::getInstance()->getStringFromFile(filename->getCString());
	vector<string> lines = split(fileText, '\n');			//�s�z��

	for (int i = counter; lines[i][0] != 'n'; i++) 
	{
		char data = lines[i][0];
		log("lines=[%s]", lines[i].c_str());
		log("data=[%c]", data);

		vector<string> blocks = split(lines[i], ',');			//�s�z��


		switch (data)
		{
		case 'F'://FLOOR
			log("F");
			FloorCreate(blocks);
			break;
		case 'S'://SHOP
			StageCreate(blocks);
			log("S");
			break;
		case 'B'://BACK
			BackCreate(blocks);

			log("B");
			break;
		case 'G'://GOAL
			log("G");
			//j++;
			//endPosition = CSVnumber;
			break;
		default:
			log("default");
			//int CSVnumber = atoi(blocks.at(i).c_str());
			//String* name = String::createWithFormat(pngName[name_count].data(), CSVnumber);

			//ShopBase* shop = ShopBase::create(CSVnumber);


			//	Sprite* spItem = Sprite::create(name->getCString());
			//spItem->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
			//spItem->setPosition(Vec2(SHOP_INTERVAL * i, heighter[height_count]));
			//addChild(spItem);
			//shop->initWithFile(name->getCString());
			//shop->setPosition(Vec2(SHOP_INTERVAL * i, heighter[height_count]));
			//shop->shopStatus.gate += SHOP_INTERVAL*i;
			//Shops->addChild(shop);
			//	if (shop->shopStatus.status == true)
				//	allShops.pushBack(shop);
			//endPosition = SHOP_INTERVAL*blocks.size();

			break;
		}
	}
	log("stop");
		//for (int j = 0; j < blocks.size(); j++)
		//{
		//	int CSVnumber = atoi(blocks.at(j).c_str());
		//		String* name = String::createWithFormat(pngName[counter].data(), CSVnumber);
		//	Sprite* spItem = Sprite::create(name->getCString());
		//	spItem->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		//	spItem->setPosition(Vec2(SHOP_INTERVAL * j, heighter[counter]));
		//	if (i == number * 5 + 4)
		//	{
		//		//goalPosition = allShops.at(CSVnumber)->shopStatus.gate;

		//		//break;
		//	}
		//
		//	if (i == number * 5 + 1)
		//	{
		//		//Floors->addChild(spItem);
		//	}
		//	if (i == number * 5 + 2)
		//	{
		//		ShopBase* shop = ShopBase::create(CSVnumber);
		//		shop->initWithFile(name->getCString());
		//		shop->setPosition(Vec2(SHOP_INTERVAL * j, heighter[counter]));
		//		shop->shopStatus.gate += SHOP_INTERVAL*j;
		//		Shops->addChild(shop);
		//		if (shop->shopStatus.status == true)
		//			allShops.pushBack(shop);
		//		endPosition = SHOP_INTERVAL*blocks.size();
		//	}
		//	if (i == number * 5 + 3)
		//	{
		//		//	BackGrounds->addChild(spItem);
		//	}
		//}
		//counter++;


};
//�v���C���[��������ꏊ
float MapCreator::getPositionPlayerX(float positionX)
{
	playerPosition = positionX;
	//log("playerPosition==%f", playerPosition);

	return positionX;
}
//���s�ʂɓ����ւ�����
void MapCreator::BackGroundMove()
{
	float XX = (playerPosition);

	BackGrounds->setPositionX(XX/10);
}


void MapCreator::FloorCreate(vector<string> letter)
{
	log("welcome To FloorCreate!");
	for (int i = 1; i < letter.size(); i++)
	{
		log("[%d,%d]", i, letter.size());
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
	log("welcome To StageCreate!"); 
	for (int i = 1; i < letter.size(); i++)
	{
		log("%c", letter[i].c_str());
		int CSVnumber = atoi(letter[i].c_str());
		log("CSVnumber=%d", CSVnumber);
		ShopBase* shop = ShopBase::create(CSVnumber);
		shop->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		shop->setPosition(Vec2(SHOP_INTERVAL * (i - 1), SHOP_HEIGHT));
		shop->shopStatus.gate += SHOP_INTERVAL * (i - 1);
		Shops->addChild(shop);
		if (shop->shopStatus.status == true)
			allShops.pushBack(shop);
		endPosition = SHOP_INTERVAL*letter.size();
	}
};

void MapCreator::BackCreate(vector<string> letter)
{
	log("welcome To BackCreate!");
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
