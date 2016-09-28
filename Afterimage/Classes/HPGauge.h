#ifndef __HP_GAUGE__
#define __HP_GAUGE__

#include "cocos2d.h"
#include "MultiResolution.h"
USING_NS_CC;

class HPGauge : public Node
{
public:
	CREATE_FUNC(HPGauge);

	Sprite *hpGauge;
	Sprite *hpWaku;

	float maxHP;

	bool init();

	void update(float delta);
	
private:

};
#endif // !__HP_GAUGE__