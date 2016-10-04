﻿#pragma execution_character_set("utf-8")

#include "StageLayer.h"
#include "GameScene.h"


#define XX designResolutionSize.width*0.7f
#define YY designResolutionSize.height*0.2f
#define PX designResolutionSize.width*0.7f
#define PY designResolutionSize.height*2.5f

bool StageLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	StageNumber = 0;
	picupNumber = 0;
	moveSpeed = 0;
	touchTimer = 0;
	numbersEye =1;
	RX = 0;
	RY = 0;

	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Music/sentaku.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("Music/button.mp3");

	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5);
	SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/sentaku.mp3", true);

	auto tap = EventListenerTouchOneByOne::create();
	tap->setSwallowTouches(true);
	tap->onTouchBegan = CC_CALLBACK_2(StageLayer::onTouchBegan, this);
	tap->onTouchMoved = CC_CALLBACK_2(StageLayer::onTouchMoved, this);
	tap->onTouchEnded = CC_CALLBACK_2(StageLayer::onTouchEnded, this);
	auto dip = Director::getInstance()->getEventDispatcher();
	dip->addEventListenerWithSceneGraphPriority(tap, this);

	map = MapCreator::create(0);

	clipMask = Sprite::create("stageMask.png");
	clipMask->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	
	clip = ClippingNode::create();
	clip->setStencil(clipMask);
	clip->setInverted(false);
	clip->setAlphaThreshold(0.0f);

	clip->addChild(map);
	addChild(clip);

	setMap(0);
	setBoard();
	setStage();
	setLetter();

	scheduleUpdate();

	return true;
};

void StageLayer::update(float delta) 
{

	if (isStageTouch) 
	{
		touchTimer += delta;
	}
		
	if (moveSpeed > 0)
	{
		moveSpeed -= 0.001f;
		if (moveSpeed <= 0.005f)
		{
			moveSpeed = 0;
		}
	}
	else if (moveSpeed < 0)
	{
		moveSpeed += 0.001f;
		if (moveSpeed >= -0.005f)
		{
			moveSpeed = 0;
		}
	}
	moveSpeed /=1500 ;

	for (int i = 0; i < Stages.size(); i++)
	{

		RX = (Stages.at(i)->getPositionX() - PX)*cos(moveSpeed) -
			(Stages.at(i)->getPositionY() - PY)*sin(moveSpeed) + PX;
		RY = (Stages.at(i)->getPositionX() - PX)*sin(moveSpeed) +
			(Stages.at(i)->getPositionY() - PY)*cos(moveSpeed) + PY;

		Stages.at(i)->setPosition(Vec2(RX, RY));

		if (desideSP->getBoundingBox().intersectsRect(Stages.at(i)->getBoundingBox()))
		{
			Stages.at(i)->setScale(0.5);
			letter->setString(Stages.at(i)->myData.LETTER);
			StageNumber = i;
			isDesided = true;
			if (i != picupNumber)
			{
				setMap(i);
				picupNumber = i;
			}
		}
		else
		{
			Stages.at(i)->setScale(0.2);

		}
		//Stages.at(i)->setColor(Color3B(moveSpeed, moveSpeed*10, moveSpeed*12));
	}
};

//画面をタッチした時の処理
bool StageLayer::onTouchBegan(Touch* touch, Event* event)
{
			isStageTouch = true;
	moveSpeed = 0;
	if (isDesided)
	{
		SimpleAudioEngine::getInstance()->playEffect("Music/buton.mp3", false);
	}
	if (touch->getLocation().x <= designResolutionSize.width*0.1f)
	{
		//Director::getInstance()->replaceScene(TransitionFade::create(2.0f, GameScene::create(StageNumber), Color3B::WHITE));
	}
	for (int i = 0; i < Stages.size(); i++)
	{
		if (Stages.at(i)->getBoundingBox().containsPoint(touch->getLocation()))
		{
			//log("get[%d]",i);
			string name = Stages.at(i)->myData.LETTER.c_str();
			letter->setString(name.c_str());
		}
	
	}
	return true;
};

//タッチ中の処理
void StageLayer::onTouchMoved(Touch* touch, Event* event)
{
		Vec2 delta = touch->getDelta();
		moveSpeed = delta.x;
	//	log("%f", moveSpeed);
};

//タッチが終わった時の処理
void StageLayer::onTouchEnded(Touch *touch, Event *event)
{
	for (int i = 0; i < Stages.size(); i++)
	{
		if (Stages.at(i)->getBoundingBox().containsPoint(touch->getLocation()))
		{
			if (isStageTouch) 
			{
				if (touchTimer <= 1) 
				{
					Director::getInstance()->replaceScene(TransitionFade::create(2.0f, GameScene::create(StageNumber), Color3B::WHITE));
				}
			}
		}
	}
};

void StageLayer::setBoard()
{

	Sprite* comment = Sprite::create("StageBoard_comment.png");
	comment->setPosition(Vec2(designResolutionSize.width*0.2f, designResolutionSize.height*0.6f));
	addChild(comment, 3);

	desideSP = Sprite::create("umbrella_0.png");
	desideSP->setPosition(Vec2(XX, YY));
	addChild(desideSP, 1);

}

void StageLayer::setStage()
{
	for (int i = 0; i <= ALL_STAGE; i++)
	{

		StageItem* sp = StageItem::create(i);
		RX = (XX - XX)*cos(((float)i/ (float)ALL_STAGE*6)) -
			(YY - PY)*sin(((float)i / (float)ALL_STAGE*6)) + PX;
		RY = (XX - XX)*sin(((float)i / (float)ALL_STAGE*6)) +
			(YY - PY)*cos(((float)i / (float)ALL_STAGE*6)) + PY;

		sp->setPosition(Vec2(RX, RY));
		sp->setScale(0.2);
		addChild(sp, 2);
		Stages.pushBack(sp);
	}
}
void StageLayer::setLetter()
{
	letter = Label::create("non letter","fonts/851H-kktt.ttf",40);
	letter->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	letter->setPosition(Vec2(designResolutionSize.width*0.1f, designResolutionSize.height*0.85f));
	addChild(letter,5);
};
void StageLayer::setMap(int number) 
{
	map->ressetStage();
	map->createStage(number);
	map->previewStage();
}