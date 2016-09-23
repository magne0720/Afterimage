#ifndef __MAP_CREATOR_H__
#define __MAP_CREATOR_H__

#include "cocos2d.h"
#include "MultiResolution.h"
#include "Player.h"
#include <iostream>
#include "ShopBase.h"

using namespace std; 

USING_NS_CC;


#define SHOP_INTERVAL 800
#define FLOOR_HEIGHT (designResolutionSize.height*0.0)
#define SHOP_HEIGHT (designResolutionSize.height*0.185)
#define START_POSITION 0

class MapCreator :public Layer
{
private:
	bool init(int number);
	int createStage(int number);

	
	//次これやる

	//ステージ生成用 
	//床(実装確定)
	Layer* Floors;
	//建物(実装確定)
	Layer* Shops;
	//背景この手紙
	Layer* BackGrounds;
	//傘(実装確定)
	Vector <Sprite*> Umbrellas; 
	//店の入口(実装予定)
	Vector <Sprite*> Gimmicks;	
	//キャラの位置

	//ショップの個体値
	ShopBase* shop;

	//ステージの最後の位置
	float playerPosition;

	void BackGroundMove();

public:
	float startPosition;
	float endPosition;

	static MapCreator* create(int number);
	void update(float delta);

	float getPositionPlayerX(float positionX);
	float myAnchor;

	//スクリプト内の直読み込み
	int createStageTest(int number);

};



#endif

