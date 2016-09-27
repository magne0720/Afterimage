#include "ResultLayer.h"
#include "TitleScene.h"


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

	auto tap = EventListenerTouchOneByOne::create();
	tap->setSwallowTouches(true);
	tap->onTouchBegan = CC_CALLBACK_2(ResultLayer::onTouchBegan, this);
	tap->onTouchMoved = CC_CALLBACK_2(ResultLayer::onTouchMoved, this);
	tap->onTouchEnded = CC_CALLBACK_2(ResultLayer::onTouchEnded, this);
	auto dip = Director::getInstance()->getEventDispatcher();
	dip->addEventListenerWithSceneGraphPriority(tap, this);



	return true;
};

void ResultLayer::update(float delta) 
{


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
