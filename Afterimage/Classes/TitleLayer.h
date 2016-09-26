#ifndef __TITLE_LAYER__
#define __TITLE_LAYER__

#include "cocos2d.h"
#include "RainManager.h"
#include "MapCreator.h"
#include "MultiResolution.h"
#include "TitleNode.h"
USING_NS_CC;

class TitleLayer : public Layer
{
public:
	CREATE_FUNC(TitleLayer);

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	//‘O
	RainManager *rainManagerA;

	MapCreator *mapCreator;
	Sprite *player;

	//Œã‚ë
	RainManager *rainManagerB;

	TitleNode *titleNode;

	bool init();


private:

	bool tapStopper;

};
#endif // !__TITLE_LAYER__