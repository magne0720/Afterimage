#include "TitleLayer.h"
#include "GameScene.h"

bool TitleLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	tapStopper = true;

	auto tap = EventListenerTouchOneByOne::create();
	tap->setSwallowTouches(true);
	tap->onTouchBegan = CC_CALLBACK_2(TitleLayer::onTouchBegan, this);
	tap->onTouchMoved = CC_CALLBACK_2(TitleLayer::onTouchMoved, this);
	tap->onTouchEnded = CC_CALLBACK_2(TitleLayer::onTouchEnded, this);
	auto dip = Director::getInstance()->getEventDispatcher();
	dip->addEventListenerWithSceneGraphPriority(tap, this);

	rainManagerA = RainManager::create(120);
	this->addChild(rainManagerA);

	mapCreator = MapCreator::create(1);
	this->addChild(mapCreator);
	player = Sprite::create("arukuRight2.png");
	player->setScale(0.18f);
	player->setPosition(Vec2(designResolutionSize.width*0.3f, designResolutionSize.height*0.3f));
	this->addChild(player);

	rainManagerB = RainManager::create(260);
	this->addChild(rainManagerB);

	titleNode = TitleNode::create();
	this->addChild(titleNode);

	rainManagerA->spCameraPos(designResolutionSize.width / 2);
	rainManagerB->spCameraPos(designResolutionSize.width / 2);

	return true;
}

//画面をタッチした時の処理
bool TitleLayer::onTouchBegan(Touch* touch, Event* event)
{
	if (tapStopper == true)
	{
		Director::getInstance()->replaceScene(TransitionFade::create(4.0f, GameScene::create(1), Color3B::WHITE));
		tapStopper = false;
	}

	return true;
}

//タッチ中の処理
void TitleLayer::onTouchMoved(Touch* touch, Event* event)
{


}

//タッチが終わった時の処理
void TitleLayer::onTouchEnded(Touch *touch, Event *event)
{
}
