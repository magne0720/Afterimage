#ifndef __UMBRELLA_CREATOR_H__
#define __UMBRELLA_CREATOR_H__

#include "cocos2d.h"
#include "Umbrella.h"

USING_NS_CC;

class UmbrellaCreator : public Node
{
public:
	CREATE_FUNC(UmbrellaCreator);

	Umbrella *umbrella[15];

	bool init();

private:

};

#endif // !