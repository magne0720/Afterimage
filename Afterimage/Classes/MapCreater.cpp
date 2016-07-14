#include "mapCreater.h"
#include <fstream>

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

	return true;
};

std::vector<std::string> MapCreater::createStage(int number)
{
	
	std::istringstream stream("stage%d.txt",number);
	log("{%s}or{%c}", stream, stream);
	std::string field;
	std::vector<std::string> result;
	char delimiter;
	int i=0;

	while (std::getline(stream, field, delimiter)) {
		result.push_back(field);
		log("%c", result[i]);
		i++;
	}
	return result;

};

void MapCreater::createObjectStage(int number)
{


};

void MapCreater::createObjectGimmick(int number)
{



};


