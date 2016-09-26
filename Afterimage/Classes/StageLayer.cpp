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

//��ʂ��^�b�`�������̏���
bool StageLayer::onTouchBegan(Touch* touch, Event* event)
{

	return true;
}

//�^�b�`���̏���
void StageLayer::onTouchMoved(Touch* touch, Event* event)
{


}

//�^�b�`���I��������̏���
void StageLayer::onTouchEnded(Touch *touch, Event *event)
{
}
