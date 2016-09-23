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

	
	//��������

	//�X�e�[�W�����p 
	//��(�����m��)
	Layer* Floors;
	//����(�����m��)
	Layer* Shops;
	//�w�i���̎莆
	Layer* BackGrounds;
	//�P(�����m��)
	Vector <Sprite*> Umbrellas; 
	//�X�̓���(�����\��)
	Vector <Sprite*> Gimmicks;	
	//�L�����̈ʒu

	//�V���b�v�̌̒l
	ShopBase* shop;

	//�X�e�[�W�̍Ō�̈ʒu
	float playerPosition;

	void BackGroundMove();

public:
	float startPosition;
	float endPosition;

	static MapCreator* create(int number);
	void update(float delta);

	float getPositionPlayerX(float positionX);
	float myAnchor;

	//�X�N���v�g���̒��ǂݍ���
	int createStageTest(int number);

};



#endif

