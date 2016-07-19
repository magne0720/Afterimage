#include "GameLayer.h"

bool GameLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	player = Player::create();
	this->addChild(player, 2);

	for (int i = 0; i < 11;i++)
	{
		Sprite* s = Sprite::create("tile.png");
		s->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		s->setPosition(Vec2( i * 200, 0));
		addChild(s);
	}

	return true;
}