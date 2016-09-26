#ifndef __UMBRELLA_H__
#define __UMBRELLA_H__

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class Umbrella : public Sprite
{
public:
	//CREATE_FUNC(Umbrella);
	static Umbrella *create(float endPos);
	//モブの速さ
	float mobspeed;
	//左右判断
	int RL;
	//生成遅延
	bool goMan;

	virtual bool init(float endPos);

	//ランダム生成
	void randomMan();
	//歩くか歩かないか
	void walk(float delta);
	//goManの切り替え
	void goManSwitch(float delta);
	void update(float delta);

	float mobEnd;
	
private:

};

#endif // !