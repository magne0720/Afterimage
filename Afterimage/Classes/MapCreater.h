#ifndef __MAP_CREATER_H__
#define __MAP_CREATER_H__

#include "cocos2d.h"

USING_NS_CC;
float RainShelter[] = { 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f };

class MapCreater :public Layer
{
private:
	

	bool init(int number);
	std::vector<std::string> createStage(int number);
	void createObjectStage(int number);
	void createObjectGimmick(int number);
	float createObjectShelter(int objectTag);

public:
	static MapCreater* create(int number);




};



#endif

