#ifndef __MAP_CREATOR_H__
#define __MAP_CREATOR_H__

#include "cocos2d.h"
#include "MultiResolution.h"
#include "Player.h"
#include <iostream>

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

	void createFloors();
	void createBuildings();
	void createUmbrellas();
	void createGimmicks();
	//��������

	//�X�e�[�W�����p 
	//��(�����m��)
	Layer* Floors;
	//����(�����m��)
	Layer* Buildings;
	//�P(�����m��)
	Vector <Sprite*> Umbrellas; 
	//�X�̓���(�����\��)
	Vector <Sprite*> Gimmicks;	
	//�L�����̈ʒu

	//�X�e�[�W�̍Ō�̈ʒu
	int endPosition;

	void BuildingMove();

public:
	static MapCreator* create(int number);
	void update(float delta);

	int getPositionPlayerX(int positionX);
	float MovementPosition;

	//�X�N���v�g���̒��ǂݍ���
	int createStageTest(int number);

};



#endif

