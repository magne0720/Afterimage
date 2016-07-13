#include "mapCreater.h"

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


	return true;
};

void createStage(int number)
{



};

void createObjectStage(int number)
{


};

void createObjectGimmick(int number)
{



};


