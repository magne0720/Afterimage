#ifndef __RESULTSCENE_H__
#define __RESULTSCENE_H__

#include "cocos2d.h"
#include "ResultLayer.h"

USING_NS_CC;

class ResultScene :public Scene 
{
public:

	static ResultScene* create(int score);
	bool init(int score);

};

#endif // !__RESULTSCENE_H__
