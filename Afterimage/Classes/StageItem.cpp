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

	allSet(number);
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
		for (int i = 0; i < blocks.size(); i++)
		{
			char data = (char)blocks[i][0];
			log("data=[%c]", data);

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
				log("%s", blocks[i].c_str());
				initWithFile(blocks[i].c_str());
				break;
			case 'S':
				i++;
				break;
			default:
				myData.LETTER += blocks[i].c_str();
				myData.LETTER.push_back('\n');
				break;
			}
		}
};