#include "UmbrellaCreator.h"

UmbrellaCreator *UmbrellaCreator::create(float endPos)

{

	UmbrellaCreator *pRet = new UmbrellaCreator();

	if (pRet && pRet->init(endPos))
	{
		pRet->autorelease();

		return pRet;
	}else{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool UmbrellaCreator::init(float endPos)
{
	if (!Node::init())
	{
		return false;
	}
	for (int i = 0; i < 15; i++)
	{
		umbrella[i] = Umbrella::create(endPos);
		umbrella[i]->setScale(0.3f);
		this->addChild(umbrella[i]);
	}

	return true;
}