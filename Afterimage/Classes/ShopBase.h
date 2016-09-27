#ifndef __SHOP_BASE_H__
#define __SHOP_BASE_H__

#include "cocos2d.h"
#include <iostream>

USING_NS_CC;
using namespace std;

class ShopBase :public Sprite
{
private:

	int shopKind;
	int shopNumber;
	float shopGate;
	void ShopCreate(int kind);



public:
	static ShopBase* create(int kind, int number);
	bool init(int kind,int number);
	void update(float delta);

	struct myShop
	{
		string name;
		float gate;
		int status;
		float min;
		float max;
	};
	myShop shopStatus;

};


#endif // !__SHOP_BASE_H__
