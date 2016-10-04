#include "TitleNode.h"

bool TitleNode::init()
{
	if (!Node::init())
	{
		return false;
	}
	title = Sprite::create("title.png");
	title->setScale(2);
	title->setPosition(Vec2(designResolutionSize.width / 2, designResolutionSize.height*0.7f));
	this->addChild(title);

	tap = Sprite::create("tapS.png");
	tap->setScale(1.5f);
	tap->setPosition(Vec2(designResolutionSize.width / 2, designResolutionSize.height*0.2f));
	this->addChild(tap);

	fadeDown = FadeTo::create(1, 0);
	fadeUp = FadeTo::create(1, 255);
	sequence = Sequence::create(fadeDown, fadeUp, NULL);
	repeatForever = RepeatForever::create(sequence);

	tap->runAction(repeatForever);




	return true;
}