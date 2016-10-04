#include "HPGauge.h"
#include "GameScene.h"

bool HPGauge::init()
{
	if (!Node::init())
	{
		return false;
	}
	hpGauge = Sprite::create("GameScene/HPwaku.png");
	hpGauge->setPosition(Vec2(designResolutionSize.width*0.1f, designResolutionSize.height*0.9f));
	hpGauge->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	this->addChild(hpGauge);

	hpWaku = Sprite::create("GameScene/HPwaku2.png");
	hpWaku->setPosition(Vec2(designResolutionSize.width*0.1f, designResolutionSize.height*0.9f));
	hpWaku->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	this->addChild(hpWaku);
	maxHP = 500.0f;

	this->scheduleUpdate();

	return true;
}

void HPGauge::update(float delta)
{
	float HP = ((float)((GameScene*)(this->getParent()))->gameLayer->PlayerHP/maxHP);
	log("%f", HP);
	if (HP > ((1.0f/3.0f)*2.0f))
	{
		hpGauge->setColor(Color3B::GREEN);
	}
	else
	{
		if (HP > (1.0f/3.0f))
		{
			hpGauge->setColor(Color3B::YELLOW);
		}
		else
		{
			hpGauge->setColor(Color3B::RED);
		}
	}

	hpGauge->setScaleX(HP);
}