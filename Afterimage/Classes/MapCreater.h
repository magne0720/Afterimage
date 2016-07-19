#ifndef __MAP_CREATER_H__
#define __MAP_CREATER_H__

#include "cocos2d.h"
#include "MultiResolution.h"
#include <string>
#include <iostream>
#include <fstream>

USING_NS_CC;

class MapCreater :public Layer
{
private:
	bool init(int number);
	int createStage(int number);

	//ステージ生成用
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
	static MapCreater* create(int number);
	void update(float delta);


	//スクリプト内の直読み込み
	int createStageTest(int number);

};



#endif

