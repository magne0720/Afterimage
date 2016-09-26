#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"
#include "Player.h"
#include "MapCreator.h"
#include "MultiResolution.h"
#include "UmbrellaCreator.h"
using namespace std;

USING_NS_CC;

class GameLayer : public Layer
{
public:
	static GameLayer *create(int fromTitle);

	bool init(int fromTitle);

	int stageNum;

	void update(float delta);

	//タッチ系
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

	/*Camera *camera;*/
	Player *player;
	Sprite *spCamera;
	UmbrellaCreator *umbrella;
	MapCreator *map;
	
private:
	//歩く速さ
	float speed;
	//左か右か
	int leftAndRightNum;
	//モブの数
	int mobNum;
	//アクションストッパー
	bool ACTswitch;
	bool direction;
};
#endif // !__GAME_LAYER_H__