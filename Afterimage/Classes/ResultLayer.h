#ifndef __RESULT_LAYER_H__
#define __RESULT_LAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class ResultLayer : public Layer
{
public:
	static ResultLayer* create(int score);
	bool init(int score);

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);


private:
	bool tapStopper;

	void update(float delta);



};


#endif // !__RESULTLAYER_H__
