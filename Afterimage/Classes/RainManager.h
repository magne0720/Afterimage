#ifndef __RAIN_MANAGER_H__
#define __RAIN_MANAGER_H__

#include "cocos2d.h"
#include "MultiResolution.h"
#include "Rain.h"
#include <vector>
USING_NS_CC;
using namespace std;

class RainManager : public Node
{
public:
	static RainManager *create(int rainNum);
	//欲しい量の雨
	Vector<Rain*> rain;
	bool init(int rainNum);
	//位置リセット
	void rainReset(Sprite *rain);
	void update(float delta);
	int spCameraMin;
	int spCameraMax;
	void spCameraPos(float pos);
	
	//雨の量
	int rainOfRain;
private:
	//速さ
	float speed;
	//粒を作りプッシュバック
	void dropCreate();
	//生成ディレイ
	float delayTime;
};
#endif // !__RAIN_MANAGER_H__