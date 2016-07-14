#ifndef __MAP_CREATER_H__
#define __MAP_CREATER_H__

#include "cocos2d.h"

USING_NS_CC;

class MapCreater :public Layer
{
private:
	bool init(int number);
	std::vector<std::string> createStage(int number);
	void createObjectStage(int number);
	void createObjectGimmick(int number);


public:
	static MapCreater* create(int number);




};



#endif

