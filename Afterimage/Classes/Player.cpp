#include "Player.h"
#include "MultiResolution.h"
bool Player::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	animeSpeed = 0.3f;

	this->initWithFile("playerRight1.png");
	this->setScale(0.1f);

	animation = Animation::create();

	animation->addSpriteFrameWithFileName("playerRight2-1.png");
	animation->addSpriteFrameWithFileName("playerRight2-2.png");
	animation->addSpriteFrameWithFileName("playerRight2-3.png");
	animation->addSpriteFrameWithFileName("playerRight2-2.png");

	animation->setDelayPerUnit(animeSpeed);
	animation->setRestoreOriginalFrame(true);

	action = Animate::create(animation);
	anime = RepeatForever::create(action);

	/*animation2 = Animation::create();

	animation2->addSpriteFrameWithFileName("playerLeft1.png");
	animation2->addSpriteFrameWithFileName("playerLeft2.png");

	animation2->setDelayPerUnit(0.5f);
	animation2->setRestoreOriginalFrame(true);

	action2 = Animate::create(animation);
	anime2 = RepeatForever::create(action);*/

	this->runAction(anime);

	this->getBoundingBox();
	return true;
}
void Player::changeLeft()
{
	this->stopAction(anime);

	animation = Animation::create();

	animation->addSpriteFrameWithFileName("playerLeft2-1.png");
	animation->addSpriteFrameWithFileName("playerLeft2-2.png");
	animation->addSpriteFrameWithFileName("playerLeft2-3.png");
	animation->addSpriteFrameWithFileName("playerLeft2-2.png");


	animation->setDelayPerUnit(animeSpeed);
	animation->setRestoreOriginalFrame(true);

	action = Animate::create(animation);
	anime = RepeatForever::create(action);
	this->runAction(anime);
}
void Player::changeRight()
{
	this->stopAction(anime);

	animation = Animation::create();

	animation->addSpriteFrameWithFileName("playerRight2-1.png");
	animation->addSpriteFrameWithFileName("playerRight2-2.png");
	animation->addSpriteFrameWithFileName("playerRight2-3.png");
	animation->addSpriteFrameWithFileName("playerRight2-2.png");


	animation->setDelayPerUnit(animeSpeed);
	animation->setRestoreOriginalFrame(true);

	action = Animate::create(animation);
	anime = RepeatForever::create(action);
	this->runAction(anime);
}