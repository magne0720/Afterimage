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

	//�X�e�[�W�����p 
	//��(�����m��)
	Vector <Sprite*> Floors;
	Sprite* createObjectFloor(int number);
	//����(�����m��)
	Vector <Sprite*> Stages;		
	Sprite* createObjectBuilding(int number);
	//�P(�����m��)
	Vector <Sprite*> Umbrellas; 
	Sprite* createObjectUmbrella(int number);
	//�X�̓���(�����\��)
	Vector <Sprite*> Gimmicks;	
	Sprite* createObjectGimmick(int number);

public:
	static MapCreator* create(int number);
	void update(float delta);


	//�X�N���v�g���̒��ǂݍ���
	int createStageTest(int number);

};



#endif

