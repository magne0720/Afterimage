#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"
#include "Player.h"

USING_NS_CC;

class GameLayer : public Layer
{
public:
	CREATE_FUNC(GameLayer);

	bool init();

	Player *player;

	
private:

};
#endif // !__GAME_LAYER_H__