#ifndef __RAIN_LAYER_H__
#define __RAIN_LAYER_H__

#include "cocos2d.h"
#include "RainManager.h"
USING_NS_CC;
class RainLayer : public Layer
{
public:
	//CREATE_FUNC(RainLayer);
	static RainLayer *create(int rainNum);

	bool init(int rainNum);
	RainManager *rainManager;


private:

};
#endif // !__RAIN_LAYER_H__