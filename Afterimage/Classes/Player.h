#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class Player : public Sprite
{
public:

	CREATE_FUNC(Player);
	bool init();

	void update(float delta);

	//タッチ系
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	
private:
	//歩く速さ
	float speed;
	//左か右か
	int leftAndRightNum;


};
#endif // !__PLAYER_H__