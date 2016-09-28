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
	//�~�����ʂ̉J
	Vector<Rain*> rain;
	bool init(int rainNum);
	//�ʒu���Z�b�g
	void rainReset(Sprite *rain);
	void update(float delta);
	int spCameraMin;
	int spCameraMax;
	void spCameraPos(float pos);
	
	//�J�̗�
	int rainOfRain;
private:
	//����
	float speed;
	//�������v�b�V���o�b�N
	void dropCreate();
	//�����f�B���C
	float delayTime;
};
#endif // !__RAIN_MANAGER_H__