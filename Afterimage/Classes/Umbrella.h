#ifndef __UMBRELLA_H__
#define __UMBRELLA_H__

#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class Umbrella : public Sprite
{
public:
	//CREATE_FUNC(Umbrella);
	static Umbrella *create(float endPos);
	//ÉÇÉuÇÃë¨Ç≥
	float mobspeed;
	//ç∂âEîªíf
	int RL;
	virtual bool init(float endPos);

	void randomMan();
	void update(float delta);

	float mobEnd;
	
private:

};

#endif // !