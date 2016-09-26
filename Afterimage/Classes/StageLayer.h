#ifndef __STAGE_LAYER__
#define __STAGE_LAYER__

#include "cocos2d.h"

USING_NS_CC;

class StageLayer : public Layer
{
public:
	CREATE_FUNC(StageLayer);

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	bool init();


private:
	void update(float delta);

};
#endif // !__Stage_LAYER__