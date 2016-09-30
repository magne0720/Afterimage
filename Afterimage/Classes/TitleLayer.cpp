#include "TitleLayer.h"
#include "GameScene.h"
#include "StageScene.h"

bool TitleLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	tapStopper = true;
	playerStopper = false;

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

	this->scheduleUpdate();

	return true;
}

//画面をタッチした時の処理
bool TitleLayer::onTouchBegan(Touch* touch, Event* event)
{
	if (tapStopper == true)
	{
		Director::getInstance()->replaceScene(TransitionFade::create(2.0f, StageScene::create(), Color3B::WHITE));
		animation = Animation::create();

		animation->addSpriteFrameWithFileName("arukuRight1.png");
		animation->addSpriteFrameWithFileName("arukuRight2.png");
		animation->addSpriteFrameWithFileName("arukuRight3.png");
		animation->addSpriteFrameWithFileName("arukuRight2.png");
		animation->setDelayPerUnit(0.3f);
		animation->setRestoreOriginalFrame(true);
		action = Animate::create(animation);
		anime = RepeatForever::create(action);

		player->runAction(anime);
		playerStopper = true;
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

void TitleLayer::update(float delta)
{
	if (playerStopper == true)
	{
		player->setPositionX(player->getPositionX() + 10.0f);
	}
}