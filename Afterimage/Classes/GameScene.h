#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "GameLayer.h"
#include "HPGauge.h"

USING_NS_CC;

class GameScene : public Scene
{
public:
	static GameScene *create(int fromTitle);

	bool init(int fromTitle);
	GameLayer *gameLayer;
	HPGauge *hpGauge;
	
private:

};
#endif // !__GAME_SCENE_H__