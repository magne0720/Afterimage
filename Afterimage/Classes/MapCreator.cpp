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

	startPosition = 0;
	endPosition = 0;

	Floors = Layer::create();
	addChild(Floors);

	Buildings = Layer::create();
	addChild(Buildings);

	BackGrounds = Layer::create();
	addChild(BackGrounds);

	createStage(number);

	scheduleUpdate();

	return true;
};

void MapCreator::update(float delta)
{
	BuildingMove();
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
		"building_%d.png",
	};

	String* filename = String::createWithFormat("Stage/StageData_001.txt", number);

	string fileText = FileUtils::getInstance()->getStringFromFile(filename->getCString());
	vector<string> lines = split(fileText, '\n');

	int counter = 1;

	for (int i = number * 4; i < number * 4 + 4; i++)
	{
		vector<string> blocks = split(lines[i], ',');

		if (i != number * 4) {

			for (int j = 0; j < blocks.size(); j++)
			{
				int CSVnumber = atoi(blocks.at(j).c_str());
				String* name = String::createWithFormat(pngName[counter].data(), CSVnumber);
				Sprite* spItem = Sprite::create(name->getCString());
				spItem->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
				spItem->setPosition(Vec2(SHOP_INTERVAL * j, heighter[counter]));
				if (i == number * 4 + 1)
					Floors->addChild(spItem);
				if (i == number * 4 + 2)
					Buildings->addChild(spItem);
				if (i == number * 4 + 3)
					BackGrounds->addChild(spItem);
			}
			counter++;
		}
		endPosition = SHOP_INTERVAL*blocks.size();
	}

	return 0;
};
//プレイヤーが今いる場所
float MapCreator::getPositionPlayerX(float positionX)
{
	playerPosition = positionX;
	log("playerPosition==%f", playerPosition);

	return positionX;
}
//奥行別に動き替えるやつ
void MapCreator::BuildingMove()
{
	float XX = ((endPosition-playerPosition)/endPosition);
	log("XX=%f", XX);
	Floors->setPositionX(XX);
	Buildings->setPositionX(XX);
	BackGrounds->setPositionX(XX);
}