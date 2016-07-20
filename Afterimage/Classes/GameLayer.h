#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"
#include "Player.h"
#include "MapCreater.h"
#include "MultiResolution.h"

USING_NS_CC;

class GameLayer : public Layer
{
public:
	CREATE_FUNC(GameLayer);

	bool init();

	void update(float delta);

	//�^�b�`�n
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

	/*Camera *camera;*/
	Player *player;
	Sprite *spr;
	MapCreater *map;

	
private:
	//��������
	float speed;
	//�����E��
	int leftAndRightNum;

};
#endif // !__GAME_LAYER_H__