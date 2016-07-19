#include "Player.h"
#include "MultiResolution.h"
bool Player::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	speed = 20.0f;
	leftAndRightNum = 0;

	auto tap = EventListenerTouchOneByOne::create();
	tap->setSwallowTouches(true);
	tap->onTouchBegan = CC_CALLBACK_2(Player::onTouchBegan, this);
	tap->onTouchMoved = CC_CALLBACK_2(Player::onTouchMoved, this);
	tap->onTouchEnded = CC_CALLBACK_2(Player::onTouchEnded, this);

	auto dip = Director::getInstance()->getEventDispatcher();
	dip->addEventListenerWithSceneGraphPriority(tap, this);

	this->initWithFile("PlantNot1.png");
	this->setScale(0.4f);
	this->setPosition(Vec2(designResolutionSize.width / 2, designResolutionSize.height*0.4));

	this->getBoundingBox();

	this->scheduleUpdate();

	return true;
}
void Player::update(float delta)
{
	//log("aaaaa");
	switch (leftAndRightNum)
	{
	case 0:
		this->setPosition(this->getPosition());
		break;
	case 1:
		this->setPositionX(this->getPositionX() + speed);
		break;
	case 2:
		this->setPositionX(this->getPositionX() - speed);
	default:
		break;
	}
}
bool Player::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {

	//画面をタッチした時の処理
	Point pos = Vec2(touch->getLocationInView().x, touch->getLocationInView().y);
	if (pos.x > designResolutionSize.width/2)
	{
		log("migi");
		leftAndRightNum = 1;
		this->initWithFile("PlantNot1.png");
	}
	if (pos.x < designResolutionSize.width/2)
	{
		log("hidari");
		leftAndRightNum = 2;
		this->initWithFile("PlantNot2.png");
	}
	return true;

}

void Player::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) {

	//タッチ中の処理

}

void Player::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event) {

	//タッチが終わった時の処理
	leftAndRightNum = 0;
}