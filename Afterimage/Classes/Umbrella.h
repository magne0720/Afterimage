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
	//���u�̑���
	float mobspeed;
	//���E���f
	int RL;
	//�����x��
	bool goMan;

	virtual bool init(float endPos);

	//�����_������
	void randomMan();
	//�����������Ȃ���
	void walk(float delta);
	//goMan�̐؂�ւ�
	void goManSwitch(float delta);
	void update(float delta);

	float mobEnd;
	
private:

};

#endif // !