#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "GameLayer.h"
#include "RainLayer.h"

USING_NS_CC;

class GameScene : public Scene
{
public:
	static GameScene *create(int fromTitle);

	bool init(int fromTitle);
	RainLayer *rainLayer;
	GameLayer *gameLayer;
	RainLayer *rainLayerb;
	void rainDelay(float delta);

	
private:

};
#endif // !__GAME_SCENE_H__