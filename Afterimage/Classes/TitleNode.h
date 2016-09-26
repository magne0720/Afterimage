#ifndef __TITLE_NODE__
#define __TITLE_NODE__

#include "cocos2d.h"
#include "MultiResolution.h"

USING_NS_CC;

class TitleNode : public Node
{
public:

	CREATE_FUNC(TitleNode);

	Sprite *title;
	Sprite *tap;

	FadeTo *fadeDown;
	FadeTo *fadeUp;
	Sequence *sequence;
	RepeatForever *repeatForever;


	bool init();
	
private:

};
#endif // !__TITLE_NODE__
