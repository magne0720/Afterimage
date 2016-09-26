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

	String* filename = String::createWithFormat("Select/Data_%03d.txt", number);

	string fileText = FileUtils::getInstance()->getStringFromFile(filename->getCString());
	vector<string> lines = split(fileText, '\n');

	for (int i = 0; i < lines.size(); i++) 
	{
		vector<string> blocks = split(lines[i], ',');

		char data = (char)lines[i][0];

		switch (data)
		{
		case 'W':
			i++;
			myData.NUMBER = atoi(lines[i].c_str());
			break;
		case 'L':	
			i++;
			myData.LEVEL = atoi(lines[i].c_str());
			break;
		case 'S':
			i++;
			myData.LETTER = lines[i].c_str();
			break;
		default:
			break;
		}
	}
};