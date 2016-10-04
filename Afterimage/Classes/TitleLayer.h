#ifndef __TITLE_LAYER__
#define __TITLE_LAYER__

#include "cocos2d.h"
#include "RainManager.h"
#include "MapCreator.h"
#include "MultiResolution.h"
#include "TitleNode.h"

#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

USING_NS_CC;

class TitleLayer : public Layer
{
public:
	CREATE_FUNC(TitleLayer);

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	Animation *animation;
	Animate *action;
	RepeatForever *anime;
	//‘O
	RainManager *rainManagerA;
	MapCreator *mapCreator;
	Sprite *player;
	//Œã‚ë
	RainManager *rainManagerB;
	TitleNode *titleNode;

	void update(float delta);
	bool init();


private:

	bool tapStopper;
	bool playerStopper;

};
#endif // !__TITLE_LAYER__