#include "HPGauge.h"
#include "GameScene.h"

HPGauge *HPGauge::create(int pHP)
{
	HPGauge *pRet = new HPGauge();
	if (pRet && pRet->init(pHP))
	{
		pRet->autorelease();
		return pRet;
	}
	else {
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool HPGauge::init(int pHP)
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
	maxHP = (float)pHP;

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