#ifndef __RAIN_H__
#define __RAIN_H__

#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class Rain : public Sprite
{
public:
	//画像出すだけ
	CREATE_FUNC(Rain);

	float speed;

	bool init();
	
private:

};
#endif // !__RAIN_H__