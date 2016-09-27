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
