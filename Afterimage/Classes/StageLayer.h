#ifndef __STAGE_LAYER_H__
#define __STAGE_LAYER_H__

#include "cocos2d.h"
#include "StageItem.h"
#include "MapCreator.h"

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
	int picupNumber;
	float numbersEye;
	float moveSpeed;
	float RX, RY;
	bool isStageTouch;
	bool isDesided;
	Sprite* desideSP;
	Sprite* clipMask;
	ClippingNode* clip;
	Label* letter;
	MapCreator* map;

	Vector<StageItem*> Stages;


	void update(float delta);

	void setMap(int number);
	void setBoard();
	void setStage();
	void setLetter();



};
#endif // !__Stage_LAYER__