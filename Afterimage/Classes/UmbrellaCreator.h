#ifndef __UMBRELLA_CREATOR_H__
#define __UMBRELLA_CREATOR_H__

#include "cocos2d.h"
#include "Umbrella.h"
#include <vector>
using namespace std;

USING_NS_CC;

class UmbrellaCreator : public Node
{
public:
	static UmbrellaCreator *create(float endPos,int ManNo);

	//Umbrella *umbrella[15];
	vector<Umbrella*> umbrella;

	virtual bool init(float endPos, int ManNo);

private:

};

#endif // !