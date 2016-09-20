#include "UmbrellaCreator.h"

bool UmbrellaCreator::init()
{
	if (!Node::init())
	{
		return false;
	}
	for (int i = 0; i < 15; i++)
	{
		umbrella[i] = Umbrella::create();
		umbrella[i]->setScale(0.3f);
		this->addChild(umbrella[i]);
	}

	return true;
}