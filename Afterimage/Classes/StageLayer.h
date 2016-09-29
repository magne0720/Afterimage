#ifndef __STAGE_LAYER_H__
#define __STAGE_LAYER_H__

#include "cocos2d.h"
#include "StageItem.h"

USING_NS_CC;

class StageLayer : public Layer
{
public:
	CREATE_FUNC(StageLayer);

	bool init();

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

private:
	int StageNumber;
	float numbersEye;
	float moveSpeed;
	float RX, RY;
	bool isStageTouch;
	Sprite* desideSP;
	Label* letter;

	Vector<StageItem*> Stages;


	void update(float delta);

	void setLetter();



};
#endif // !__Stage_LAYER__