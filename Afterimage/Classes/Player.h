#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class Player : public Sprite
{
public:

	CREATE_FUNC(Player);

	float animeSpeed;
	Animation *animation;
	Animate *action;
	RepeatForever *anime;
	void changeLeft();
	void changeRight();



	bool init();
	
private:

};
#endif // !__PLAYER_H__