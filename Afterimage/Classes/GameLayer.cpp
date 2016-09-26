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
	direction = true;

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
	                                   //ゴール位置　生成数
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
	player->changeLeft();
	player->stopAct(2);
	player->changeRight();
	player->stopAct(1);

	this->scheduleUpdate();
	return true;
}

void GameLayer::update(float delta)
{
	//マップにプレイヤーの位置を送る
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

	for (int i = 0; i < mobNum; i++)
	{
		if (player->getBoundingBox().intersectsRect(umbrella->umbrella[i]->getBoundingBox()))
		{
		}
		for (int j = 0; j < map->allShops.size(); j++)
		{
			if (umbrella->umbrella[i]->getBoundingBox().containsPoint(Point(map->allShops.at(j)->shopStatus.gate,designResolutionSize.height*0.4f)))
			{
				//log("size.at=[%d]",j);
				random_device rd;
				mt19937 mt(rd());
				uniform_int_distribution<int> erasure(0,3);
				//if (erasure(mt) == 0)
				//{
				//	umbrella->umbrella[i]->stopRandomOFF();
				//}
				//else
				//{
				//	umbrella->umbrella[i]->randomMan();
				//}
				switch (erasure(mt))
				{
				case 2:
					umbrella->umbrella[i]->randomMan();
					break;
				case 3:

					break;
				default:
					umbrella->umbrella[i]->stopRandomOFF();
					break;
				}
			}
		}
	}
}

//画面をタッチした時の処理
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

//タッチ中の処理
void GameLayer::onTouchMoved(Touch* touch, Event* event)
{


}

//タッチが終わった時の処理
void GameLayer::onTouchEnded(Touch *touch, Event *event)
{
	player->stopAct(leftAndRightNum);
	leftAndRightNum = 0;
	direction = true;
}