﻿#ifndef __RESULT_LAYER_H__
#define __RESULT_LAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class ResultLayer : public Layer
{
public:
	static ResultLayer* create(int score);
	bool init(int score);

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);


private:
	int endScore;
	int clockCounter;	
	bool tapStopper;
	float takeTimer;
	float takeClock[5]=
	{
		1.0f,
		2.0f,
		3.0f,
		5.0f,
		0
	};
	float* pClock;

	Vector<Label*> scoreBoards;
	Vector<Sprite*> Umbrellas;
	int umum;

	void update(float delta);
	void makeBoard();
	void missBoard();




};


#endif // !__RESULTLAYER_H__
