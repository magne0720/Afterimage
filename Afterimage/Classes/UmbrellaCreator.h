#ifndef __UMBRELLA_CREATOR_H__
#define __UMBRELLA_CREATOR_H__

#include "cocos2d.h"
#include "Umbrella.h"

USING_NS_CC;

class UmbrellaCreator : public Node
{
public:
	static UmbrellaCreator *create(float endPos);

	Umbrella *umbrella[15];

	virtual bool init(float endPos);

private:

};

#endif // !