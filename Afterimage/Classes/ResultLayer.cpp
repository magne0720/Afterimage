#pragma execution_character_set("utf-8")

#include "ResultLayer.h"
#include "TitleScene.h"
#include "MultiResolution.h"


ResultLayer* ResultLayer::create(int score)
{
	ResultLayer *pRet = new ResultLayer();
	if (pRet && pRet->init(score))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}

}

bool ResultLayer::init(int score)
{
	if (!Layer::init())
	{
		return false;
	}
	clockCounter = 0;
	tapStopper = false;
	takeTimer = 0;
	pClock = takeClock;

	auto tap = EventListenerTouchOneByOne::create();
	tap->setSwallowTouches(true);
	tap->onTouchBegan = CC_CALLBACK_2(ResultLayer::onTouchBegan, this);
	tap->onTouchMoved = CC_CALLBACK_2(ResultLayer::onTouchMoved, this);
	tap->onTouchEnded = CC_CALLBACK_2(ResultLayer::onTouchEnded, this);
	auto dip = Director::getInstance()->getEventDispatcher();
	dip->addEventListenerWithSceneGraphPriority(tap, this);

	for (float f = 0; f < 1;f+=0.1)
	{
		for (float g = 0; g < 1;g+=0.1)
		{
			Sprite* sp = Sprite::create("umbrella_0.png");
			sp->setPosition(Vec2(designResolutionSize.width*f, designResolutionSize.height*g));
			addChild(sp);
		}
	}
	
	makeBoard();

	scheduleUpdate();

	return true;
};

void ResultLayer::update(float delta) 
{
	takeTimer += delta;
	if (!*pClock == 0) {
		if (takeTimer >= *pClock)
		{
			log("timeIn_float=[%f]", *pClock);
			scoreBoards.at(clockCounter)->setVisible(true);
			pClock++;
			clockCounter++;
		}
	}
	else
	{
		if(!tapStopper)
		tapStopper = true;
	}

};

//画面をタッチした時の処理
bool ResultLayer::onTouchBegan(Touch* touch, Event* event)
{
	if (tapStopper == true)
	{
		Director::getInstance()->replaceScene(TransitionFade::create(4.0f, TitleScene::create(), Color3B::WHITE));
		tapStopper = false;
	}

	return true;
};

//タッチ中の処理
void ResultLayer::onTouchMoved(Touch* touch, Event* event)
{


};

//タッチが終わった時の処理
void ResultLayer::onTouchEnded(Touch *touch, Event *event)
{


};

void ResultLayer::makeBoard()
{
	string strItem[5] =
	{
		"1,クリア",
		"2,すげええ",
		"3,スコア\t%d",
		"4,マッチョ",
		"5,huwaa",
	};

	for (int i = 0; i<sizeof(takeClock) / sizeof(takeClock[0]); i++)
	{
		String* name = String::createWithFormat(strItem[i].c_str(), score);
		Label* pLabel = Label::create(name->getCString(),"arial",100);
		pLabel->setPosition(Vec2(designResolutionSize.width*0.5f, designResolutionSize.height *0.7f-(i*100)));
		pLabel->setVisible(false);
		addChild(pLabel);
		scoreBoards.pushBack(pLabel);
	}
};