#ifndef __STAGE_SCENE__
#define __STAGE_SCENE__

#include "cocos2d.h"
#include "StageLayer.h"

USING_NS_CC;

class StageScene : public Scene
{
public:
	CREATE_FUNC(StageScene);
	StageLayer *StageLayer;




	bool init();


private:

};
#endif // !