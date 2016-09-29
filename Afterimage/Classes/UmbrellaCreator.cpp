#include "UmbrellaCreator.h"

UmbrellaCreator *UmbrellaCreator::create(float endPos,int ManNo)

{

	UmbrellaCreator *pRet = new UmbrellaCreator();

	if (pRet && pRet->init(endPos,ManNo))
	{
		pRet->autorelease();

		return pRet;
	}else{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool UmbrellaCreator::init(float endPos, int ManNo)
{
	if (!Node::init())
	{
		return false;
	}

	for (int i = 0; i < ManNo; i++)
	{
		umbrella.push_back(Umbrella::create(endPos));
		umbrella[i]->setScale(1.6f);
		this->addChild(umbrella[i]);
	}



	return true;
}