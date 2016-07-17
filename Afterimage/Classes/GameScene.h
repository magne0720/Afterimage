#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "GameLayer.h"

USING_NS_CC;

class GameScene : public Scene
{
public:
	CREATE_FUNC(GameScene);

	bool init();

	GameLayer *gameLayer;

	
private:

};
#endif // !__GAME_SCENE_H__