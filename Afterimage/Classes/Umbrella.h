#ifndef __UMBRELLA_H__
#define __UMBRELLA_H__

#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class Umbrella : public Sprite
{
public:
	CREATE_FUNC(Umbrella);
	//���u�̑���
	float mobspeed;
	//���E���f
	int RL;
	bool init();

	void randomMan();
	void update(float delta);

	
private:

};
#endif // !