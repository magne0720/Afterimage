#ifndef __MAP_CREATER_H__
#define __MAP_CREATER_H__

#include "cocos2d.h"
#include "MultiResolution.h"
#include <string>
#include <iostream>
#include <fstream>

USING_NS_CC;


#define SHOP_INTERVAL 800
#define FLOOR_HEIGHT designResolutionSize.height*0.0
#define SHOP_HEIGHT designResolutionSize.height*0.185

class MapCreator :public Layer
{
private:
	bool init(int number);
	int createStage(int number);

	//ステージ生成用 
	//床(実装確定)
	Vector <Sprite*> Floors;
	Sprite* createObjectFloor(int number);
	//建物(実装確定)
	Vector <Sprite*> Stages;		
	Sprite* createObjectBuilding(int number);
	//傘(実装確定)
	Vector <Sprite*> Umbrellas; 
	Sprite* createObjectUmbrella(int number);
	//店の入口(実装予定)
	Vector <Sprite*> Gimmicks;	
	Sprite* createObjectGimmick(int number);

public:
	static MapCreator* create(int number);
	void update(float delta);


	//スクリプト内の直読み込み
	int createStageTest(int number);

};



#endif

