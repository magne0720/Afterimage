#include "HPGauge.h"
#include "GameScene.h"

bool HPGauge::init()
{
	if (!Node::init())
	{
		return false;
	}
	hpGauge = Sprite::create("HPwaku.png");
	hpGauge->setPosition(Vec2(designResolutionSize.width*0.1f, designResolutionSize.height*0.9f));
	hpGauge->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	this->addChild(hpGauge);

	hpWaku = Sprite::create("HPgauge.png");
	hpWaku->setPosition(Vec2(designResolutionSize.width*0.1f, designResolutionSize.height*0.9f));
	hpWaku->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	this->addChild(hpWaku);

	this->scheduleUpdate();

	return true;
}

void HPGauge::update(float delta)
{
	float HP = (float)((GameScene*)(this->getParent()))->gameLayer->PlayerHP;
	hpGauge->setScaleX(HP / 500.0f);
}