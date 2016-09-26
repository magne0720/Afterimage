#ifndef __TITLE_SCENE__
#define __TITLE_SCENE__

#include "cocos2d.h"
#include "TitleLayer.h"

USING_NS_CC;

class TitleScene : public Scene
{
public:
	CREATE_FUNC(TitleScene);
	TitleLayer *titleLayer;




	bool init();

	
private:

};
#endif // !