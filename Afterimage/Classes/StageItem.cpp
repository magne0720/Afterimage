#pragma execution_character_set("utf-8")

#include "StageItem.h"


StageItem* StageItem::create(int number)
{
	StageItem *pRet = new StageItem();
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

}

bool StageItem::init(int number) 
{
	if(!Sprite::init())
	{
		return false;
	}
	if (number != ALL_STAGE)
		allSet(number);
	else
		randomSet();
	
	log("getStageItem");


	return true;
};

void StageItem::allSet(int number)
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

	String* filename = String::createWithFormat("Select/Data.txt");

	string fileText = FileUtils::getInstance()->getStringFromFile(filename->getCString());
	vector<string> lines = split(fileText, '\n');
	vector<string> blocks = split(lines[number], ',');
	vector<string> letters;


	for (int i = 0; i < blocks.size(); i++)
	{
		char data = blocks[i][0];
		switch (data)
		{
		case 'W':
			i++;
			myData.NUMBER = atoi(blocks[i].c_str());
			break;
		case 'L':
			i++;
			myData.LEVEL = atoi(blocks[i].c_str());
			break;
		case 'T':
			i++;
			initWithFile(blocks[i].c_str());
			break;
		case 'S':
			i++;
			letters = split(blocks[i], '@');
			for (int j = 0; j < letters .size(); j++)
			{
				myData.LETTER += letters[j] + '\n';
			}
			break;
		default:
			break;


		}
	}
	log("%s", myData.LETTER.c_str());
};

void StageItem::randomSet()
{

	myData.LEVEL = -1;
	myData.NUMBER = -1;
	myData.LETTER = "random";
	initWithFile("random.png");

}