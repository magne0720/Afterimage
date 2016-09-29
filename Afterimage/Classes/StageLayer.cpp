#pragma execution_character_set("utf-8")

#include "StageLayer.h"
#include "GameScene.h"

#define ALL_STAGE 30
#define XX designResolutionSize.width*0.7f
#define YY designResolutionSize.height*0.1f
#define PX designResolutionSize.width*0.7f
#define PY designResolutionSize.height*2.5f

bool StageLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	StageNumber = 0;
	moveSpeed = 0;
	numbersEye =1;
	RX = 0;
	RY = 0;

	auto tap = EventListenerTouchOneByOne::create();
	tap->setSwallowTouches(true);
	tap->onTouchBegan = CC_CALLBACK_2(StageLayer::onTouchBegan, this);
	tap->onTouchMoved = CC_CALLBACK_2(StageLayer::onTouchMoved, this);
	tap->onTouchEnded = CC_CALLBACK_2(StageLayer::onTouchEnded, this);
	auto dip = Director::getInstance()->getEventDispatcher();
	dip->addEventListenerWithSceneGraphPriority(tap, this);

	
	Sprite* comment = Sprite::create("StageBoard_comment.png");
	comment->setPosition(Vec2(designResolutionSize.width*0.2f, designResolutionSize.height*0.6f));
	addChild(comment,3);

	desideSP = Sprite::create("umbrella_0.png");
	desideSP->setPosition(Vec2(XX, YY));
	addChild(desideSP,1);

	for (int i = 0; i < ALL_STAGE; i++) 
	{
		StageItem* sp = StageItem::create(i);
	RX = (XX - XX)*cos((float)(i*0.2)) -
		(YY - PY)*sin((float)(i*0.2)) + PX;
	RY = (XX - XX)*sin((float)(i*0.2)) +
		(YY - PY)*cos((float)(i*0.2)) + PY;

		sp->setPosition(Vec2(RX,RY));
		sp->setScale(0.2);
		addChild(sp,2);
		Stages.pushBack(sp);
	}
	setLetter();

	scheduleUpdate();

	return true;
};

void StageLayer::update(float delta) 
{
		
	if (moveSpeed > 0)
		moveSpeed = 0.003f;
	else if (moveSpeed < 0)
		moveSpeed = -0.003f;

		
	for (int i = 0; i < Stages.size(); i++)
	{

		RX = (Stages.at(i)->getPositionX() - PX)*cos(moveSpeed) -
			(Stages.at(i)->getPositionY() - PY)*sin(moveSpeed) + PX;
		RY = (Stages.at(i)->getPositionX() - PX)*sin(moveSpeed) +
			(Stages.at(i)->getPositionY() - PY)*cos(moveSpeed) + PY;

		Stages.at(i)->setPosition(Vec2(RX, RY));

		if (desideSP->getBoundingBox().intersectsRect(Stages.at(i)->getBoundingBox()))
		{
			letter->setString(Stages.at(i)->myData.LETTER);
			StageNumber = i;
		}

		//Stages.at(i)->setColor(Color3B(moveSpeed, moveSpeed*10, moveSpeed*12));
	}
};

//画面をタッチした時の処理
bool StageLayer::onTouchBegan(Touch* touch, Event* event)
{
	moveSpeed = 0;

	if (touch->getLocation().x >= designResolutionSize.width*0.9f)
	{
		Director::getInstance()->replaceScene(TransitionFade::create(2.0f, GameScene::create(StageNumber), Color3B::WHITE));
	}
	for (int i = 0; i < Stages.size(); i++)
	{
		if (Stages.at(i)->getBoundingBox().containsPoint(touch->getLocation()))
		{
			log("get[%d]",i);
			String* name = String::createWithFormat(Stages.at(i)->myData.LETTER.c_str());
			letter->setString(name->getCString());
			Stages.at(i)->myData.LETTER.c_str();
			isStageTouch = true;
		}
	}
	return true;
};

//タッチ中の処理
void StageLayer::onTouchMoved(Touch* touch, Event* event)
{
	if (isStageTouch)
	{
		Vec2 delta = touch->getDelta();
		moveSpeed = delta.x;
	}
};

//タッチが終わった時の処理
void StageLayer::onTouchEnded(Touch *touch, Event *event)
{
	isStageTouch = false;

};

void StageLayer::setLetter()
{
	letter = Label::create("ここに説明文はいるんだけどね","arial.ttf",40);
	letter->setPosition(Vec2(designResolutionSize.width*0.2f, designResolutionSize.height*0.85f));
	addChild(letter,5);
};