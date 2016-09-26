#include "StageLayer.h"
#include "GameScene.h"

bool StageLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto tap = EventListenerTouchOneByOne::create();
	tap->setSwallowTouches(true);
	tap->onTouchBegan = CC_CALLBACK_2(StageLayer::onTouchBegan, this);
	tap->onTouchMoved = CC_CALLBACK_2(StageLayer::onTouchMoved, this);
	tap->onTouchEnded = CC_CALLBACK_2(StageLayer::onTouchEnded, this);
	auto dip = Director::getInstance()->getEventDispatcher();
	dip->addEventListenerWithSceneGraphPriority(tap, this);




	return true;
}

//画面をタッチした時の処理
bool StageLayer::onTouchBegan(Touch* touch, Event* event)
{

	return true;
}

//タッチ中の処理
void StageLayer::onTouchMoved(Touch* touch, Event* event)
{


}

//タッチが終わった時の処理
void StageLayer::onTouchEnded(Touch *touch, Event *event)
{
}
