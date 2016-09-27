#include "GameLayer.h"

GameLayer *GameLayer::create(int fromTitle)

{

	GameLayer *pRet = new GameLayer();

	if (pRet && pRet->init(fromTitle))
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

bool GameLayer::init(int fromTitle)
{
	if (!Layer::init())
	{
		return false;
	}
	stageNum = fromTitle;
	speed = 15.0f;
	leftAndRightNum = 0;
	mobNum = 20;
	ACTswitch = true;
	shopstop = true;
	direction = true;
	goalStop = true;

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


	spCamera = Sprite::create();
	spCamera->setPosition(Vec2(designResolutionSize.width / 2, designResolutionSize.height / 2));
	this->addChild(spCamera);

	map = MapCreator::create(1);
	addChild(map);
	                                   //�S�[���ʒu�@������
	umbrella = UmbrellaCreator::create(map->endPosition,mobNum);
	//umbrella->setPosition(Vec2(designResolutionSize.width * 0, designResolutionSize.height *0));
	this->addChild(umbrella, 1);

	//for (int i = 0; i < 11;i++)
	//{
	//	Sprite* s = Sprite::create("tile.png");
	//	s->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	//	s->setPosition(Vec2( i * 200, 0));
	//	addChild(s);
	//}
	//this->runAction(Follow::create(player));
	for (int n = 0; n < mobNum; n++)
	{
		random_device rd;
		mt19937 mt(rd());
		uniform_int_distribution<int> shopOrEnd(0, 1);
		if (shopOrEnd(mt) == 0)
		{
			shopstop = false;
			this->schedule(schedule_selector(GameLayer::shopStopON), 6);
			umbrella->umbrella[n]->randomMan();

		}
		else
		{
			umbrella->umbrella[n]->stopRandomOFF();
			mobShop(n);
		}
	}

	player->changeLeft();
	player->stopAct(2);
	player->changeRight();
	player->stopAct(1);

	this->scheduleUpdate();
	return true;
}

void GameLayer::update(float delta)
{
	//�}�b�v�Ƀv���C���[�̈ʒu�𑗂�
	map->getPositionPlayerX(spCamera->getPositionX());

	if (player->getPositionX() < designResolutionSize.width / 2)
	{
		spCamera->setPositionX(spCamera->getPositionX());
	}
	else
	{
		spCamera->setPositionX(player->getPositionX());
	}

	if (player->getPositionX() /*+ (player->getContentSize().width/2)*/ <= designResolutionSize.width * 0)
	{
		player->setPositionX(player->getPositionX() + speed);
	}

	switch (leftAndRightNum)
	{
	case 0:
		player->setPosition(player->getPosition());
		break;
	case 1:
		player->setPositionX(player->getPositionX() + speed);
		break;
	case 2:
		player->setPositionX(player->getPositionX() - speed);
	default:
		break;
	}
	random_device rd;
	mt19937 mt(rd());
	if (player->getBoundingBox().containsPoint(Point(map->goalPosition, designResolutionSize.height*0.4f)))
	{
		if (goalStop == true)
		{
			goalStop = false;
			log("G--------O---------A--------L");
		}
	}
	for (int i = 0; i < mobNum; i++)
	{
		if (player->getBoundingBox().intersectsRect(umbrella->umbrella[i]->getBoundingBox()))
		{

		}
		for (int j = 0; j < map->openShops.size(); j++)
		{
			if (umbrella->umbrella[i]->getBoundingBox().containsPoint(Vec2(map->openShops.at(j)->shopStatus.gate,designResolutionSize.height*0.4f)))
			{
				random_device rd;
				mt19937 mt(rd());
				uniform_int_distribution<int> erasure(0,3);
				switch (erasure(mt))
				{
				case 0:
					mobShop(i);
					break;
				case 1:
					mobShop(i);
					break;
				default:
					umbrella->umbrella[i]->stopRandomOFF();

					break;
				}
			}
		}
	}

}

//��ʂ��^�b�`�������̏���
bool GameLayer::onTouchBegan(Touch* touch, Event* event)
{
	Point pos = Vec2(touch->getLocationInView().x, touch->getLocationInView().y);
	if (ACTswitch == true)
	{
		this->runAction(Follow::create(spCamera));
		ACTswitch = false;
	}
	if (pos.x > designResolutionSize.width / 2)
	{
		log("migi");
		leftAndRightNum = 1;
		if (direction == true)
		{
			player->changeRight();
			direction = false;
		}
		//player->initWithFile("PlantNot1.png");
	}
	if (pos.x < designResolutionSize.width / 2)
	{
		log("hidari");
		leftAndRightNum = 2;
		if (direction == true)
		{
			player->changeLeft();
			direction = false;
		}
		//player->initWithFile("PlantNot2.png");

	}

	
	return true;

}

//�^�b�`���̏���
void GameLayer::onTouchMoved(Touch* touch, Event* event)
{


}

//�^�b�`���I��������̏���
void GameLayer::onTouchEnded(Touch *touch, Event *event)
{
	player->stopAct(leftAndRightNum);
	leftAndRightNum = 0;
	direction = true;
}

void GameLayer::mobShop(int mobNum)
{
	if (shopstop == true)
	{
		shopstop = false;
		umbrella->umbrella[mobNum]->stopRandomOFF();
		random_device rd;
		mt19937 mt(rd());
		//log("mapSize%d", map->allShops.size());
		int mSize = map->openShops.size();
		uniform_int_distribution<int> randomShop(0, (mSize - 1));
		uniform_int_distribution<int> RLor(1,2);
		umbrella->umbrella[mobNum]->RL = RLor(mt);
		umbrella->umbrella[mobNum]->stockRL = umbrella->umbrella[mobNum]->RL;
		umbrella->umbrella[mobNum]->setPositionX(map->openShops.at(randomShop(mt))->shopStatus.gate);
		this->schedule(schedule_selector(GameLayer::shopStopON), 3);
	}
}

void GameLayer::shopStopON(float delta)
{
	shopstop = true;
}