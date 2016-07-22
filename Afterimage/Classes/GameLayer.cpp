#include "GameLayer.h"

bool GameLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	speed = 15.0f;
	leftAndRightNum = 0;

	auto tap = EventListenerTouchOneByOne::create();
	tap->setSwallowTouches(true);
	tap->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);
	tap->onTouchMoved = CC_CALLBACK_2(GameLayer::onTouchMoved, this);
	tap->onTouchEnded = CC_CALLBACK_2(GameLayer::onTouchEnded, this);
	auto dip = Director::getInstance()->getEventDispatcher();
	dip->addEventListenerWithSceneGraphPriority(tap, this);

	player = Player::create();
	player->setPosition(Vec2(designResolutionSize.width / 2, designResolutionSize.height*0.3f));
	this->addChild(player, 2);

	////*camera = Camera::create();
	//camera->getCameraMask();
	//camera->setPosition(Vec2(designResolutionSize.width*0, designResolutionSize.height*0));
	//this->addChild(camera);*/
	////*auto camera = new ActionCamera();
	////camera->autorelease();
	//camera->setTarget(player);*/
	////this->runAction(Follow::create(player));

	spr = Sprite::create();
	spr->setPosition(Vec2(designResolutionSize.width / 2, designResolutionSize.height / 2));
	this->addChild(spr);


	map = MapCreator::create(1);
	addChild(map);

	/*for (int i = 0; i < 11;i++)
	{
		Sprite* s = Sprite::create("tile.png");
		s->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		s->setPosition(Vec2( i * 200, 0));
		addChild(s);
	}*/

	//this->runAction(Follow::create(player));

	this->scheduleUpdate();
	return true;
}
void GameLayer::update(float delta)
{
	spr->setPositionX(player->getPositionX());
	switch (leftAndRightNum)
	{
	case 0:
		player->setPosition(player->getPosition());
		break;
	case 1:
		player->setPositionX(player->getPositionX() + speed);
		this->runAction(Follow::create(spr));
		break;
	case 2:
		player->setPositionX(player->getPositionX() - speed);
		this->runAction(Follow::create(spr));
	default:
		break;
	}
}
//画面をタッチした時の処理
bool GameLayer::onTouchBegan(Touch* touch, Event* event)
{
	Point pos = Vec2(touch->getLocationInView().x, touch->getLocationInView().y);
	if (pos.x > designResolutionSize.width / 2)
	{
		log("migi");
		leftAndRightNum = 1;
		player->initWithFile("PlantNot1.png");
	}
	if (pos.x < designResolutionSize.width / 2)
	{
		log("hidari");
		leftAndRightNum = 2;
		player->initWithFile("PlantNot2.png");
	}

	
	return true;

}
//タッチ中の処理
void GameLayer::onTouchMoved(Touch* touch, Event* event)
{


}
//タッチが終わった時の処理
void GameLayer::onTouchEnded(Touch *touch, Event *event)
{

	leftAndRightNum = 0;
}