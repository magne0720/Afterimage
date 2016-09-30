#ifndef __STAGE_ITEM_H__
#define __STAGE_ITEM_H__

#include "cocos2d.h"
#include <iostream>

USING_NS_CC;
using namespace std;


#define ALL_STAGE 30

class StageItem:public Sprite
{
public:
	static StageItem* create(int number);
	bool init(int number);
	void allSet(int number);
	void randomSet();

	struct MYDATA
	{
		int LEVEL;
		int NUMBER;
		string LETTER;
	};
	MYDATA myData;

};



#endif //!__STAGE_ITEM_H__
