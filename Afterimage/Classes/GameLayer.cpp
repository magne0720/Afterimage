#include "GameLayer.h"
#include "ResultScene.h"
#include "GameScene.h"

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
	PlayerHP = 500;
	speed = 10.0f;
	leftAndRightNum = 0;
	mobNum = 25;
	ACTswitch = true;
	shopstop = true;
	direction = true;
	goalStop = true;
	tapStop = true;
	actStop = false;

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

	map = MapCreator::create(stageNum);
	addChild(map);

	rainManagerBack = RainManager::create(120);
	this->addChild(rainManagerBack, 0);

	rainManager = RainManager::create(260);
	this->addChild(rainManager, 4);
	                                   //ゴール位置　生成数
	umbrella = UmbrellaCreator::create(map->endPosition,mobNum);
	//umbrella->setPosition(Vec2(designResolutionSize.width * 0, designResolutionSize.height *0));
	this->addChild(umbrella, 3);


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
		angerGauge.push_back(0);
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
	actStop = true;

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
	rainManagerBack->spCameraPos(spCamera->getPositionX());
	rainManager->spCameraPos(spCamera->getPositionX());


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
			Director::getInstance()->replaceScene(ResultScene::create(PlayerHP));
			log("G--------O---------A--------L");
		}
	}
	if (!hit())
	{
		PlayerHP--;
	}
	if (PlayerHP < 0)
	{
		if (goalStop == true)
		{
			goalStop = false;
			Director::getInstance()->replaceScene(ResultScene::create(0));
		}

	}
	//log("%d", PlayerHP);

	for (int i = 0; i < mobNum; i++)
	{
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
		if (tapStop)
		{
			if (player->getBoundingBox().intersectsRect(umbrella->umbrella[i]->getBoundingBox()))
			{
				log("%d hit!", i);
				switch (umbrella->umbrella[i]->stockRL)
				{
				case 1:
					if (player->getPositionX() > umbrella->umbrella[i]->getPositionX())
					{
						angerGauge[i]++;
						if (angerGauge[i] > umbrella->umbrella[i]->angerMax)
						{
							angerGauge[i] = 0;
							umbrella->umbrella[i]->setFlipX(false);
							playerLoss(i);
						}
						log("hanbunkoeta");
					}
					break;
				case 2:
					if (player->getPositionX() < umbrella->umbrella[i]->getPositionX())
					{
						angerGauge[i]++;
						if (angerGauge[i] > umbrella->umbrella[i]->angerMax)
						{
							angerGauge[i] = 0;
							umbrella->umbrella[i]->setFlipX(true);
							playerLoss(i);
						}
					}
					break;
				default:
					break;
				}
			}
			else
			{
				angerGauge[i]--;
				if (angerGauge[i] <= 0 )
				{
					angerGauge[i] = 0;
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
	if (tapStop)
	{
		if (pos.x > designResolutionSize.width / 2)
		{
			log("migi");
			leftAndRightNum = 1;
			if (direction == true)
			{
				player->changeRight();
				direction = false;
			}
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

		}
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

void GameLayer::mobShop(int mobNum)
{
	if (shopstop == true)
	{
		shopstop = false;
		umbrella->umbrella[mobNum]->stopRandomOFF();
		if (actStop)
		{
			Sprite *copyUmbrella = Sprite::create("umbrellaMob.png");
			if (umbrella->umbrella[mobNum]->stockRL == 1)
			{
				copyUmbrella->setFlipX(true);
			}
			copyUmbrella->setPosition(umbrella->umbrella[mobNum]->getPosition());
			copyUmbrella->setScale(umbrella->umbrella[mobNum]->getScale());
			this->addChild(copyUmbrella);
			copyUmbrella->runAction(Sequence::create(FadeOut::create(1.0f), RemoveSelf::create(true), NULL));
		}

		random_device rd;
		mt19937 mt(rd());
		//log("mapSize%d", map->allShops.size());
		int mSize = map->openShops.size();
		uniform_int_distribution<int> randomShop(0, (mSize - 1));
		uniform_int_distribution<int> RLor(1,2);
		umbrella->umbrella[mobNum]->RL = RLor(mt);
		umbrella->umbrella[mobNum]->stockRL = umbrella->umbrella[mobNum]->RL;
		umbrella->umbrella[mobNum]->RLJudge(0);
		umbrella->umbrella[mobNum]->setPositionX(map->openShops.at(randomShop(mt))->shopStatus.gate);
		umbrella->umbrella[mobNum]->setOpacity(0);
		umbrella->umbrella[mobNum]->runAction(FadeIn::create(0.5f));
		this->schedule(schedule_selector(GameLayer::shopStopON), 3);
	}
}

void GameLayer::shopStopON(float delta)
{
	shopstop = true;
}

bool GameLayer::hit()
{
	//int hitNum = 0;
	bool isShop = false;
	bool isUmbrella = false;
	for (int t = 0; t < map->allShops.size(); t++)
	{
		if (player->getBoundingBox().intersectsRect(map->allShops.at(t)->getBoundingBox()))
		{
			log("[%f],[%f]" ,map->allShops.at(t)->shopStatus.min, map->allShops.at(t)->shopStatus.max);
			if (player->getPositionX() > map->allShops.at(t)->shopStatus.min &&
				player->getPositionX() < map->allShops.at(t)->shopStatus.max)
			{
				isShop = true;
			}
			
		}
	}
	for (int s = 0; s < mobNum; s++)
	{
		if (player->getBoundingBox().intersectsRect(umbrella->umbrella[s]->getBoundingBox()))
		{
			isUmbrella = true;
			s = mobNum;
		}
	}

	if (isShop|| isUmbrella)//安全
	{
		return true;
	}
	else//死
	{
		return false;
	}
}

void GameLayer::playerLoss(int mob)
{
	tapStop = false;
	if (leftAndRightNum == 2)
	{
		move = MoveBy::create(0.03f, Vec2(200.0f, 0));
		mobMove = MoveBy::create(0.03f, Vec2(100.0f, 0));
	}
	else
	{
	    move = MoveBy::create(0.03f, Vec2(-200.0f, 0));
		mobMove = MoveBy::create(0.03f, Vec2(-100.0f, 0));
	}
	leftAndRightNum = 0;
	umbrella->umbrella[mob]->runAction(mobMove);
	player->runAction(move);
	player->runAction(Blink::create(1.5f, 8));
	this->scheduleOnce(schedule_selector(GameLayer::mobLookBack), 0.2f);
	this->scheduleOnce(schedule_selector(GameLayer::lossRelease), 1.5f);

}

void GameLayer::lossRelease(float delta)
{
	tapStop = true;
}

void GameLayer::mobLookBack(float delta)
{
	for (int i = 0; i < mobNum; i++)
	{
		umbrella->umbrella[i]->RLJudge(0);
	}
}