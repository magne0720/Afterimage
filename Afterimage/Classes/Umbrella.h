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
	//�ۑ��p���E���f
	int stockRL;
	//���E���f
	int RL;
	//�{��₷��
	int angerMax;
	//�����x��
	bool goMan;
	//�����_���X�^�b�p�[
	bool stopRandom;

	virtual bool init(float endPos);

	//�����_������
	void randomMan();
	//�����������Ȃ���
	void walk(float delta);
	//goMan�̐؂�ւ�
	void goManSwitch(float delta);
	//stopRandom�̐؂�ւ�
	void stopRandomOFF();
	void stopRandomON(float delta);
	void leftRightMan(float delta);
	//���E���f
	void RLJudge(float delta);


	void update(float delta);

	float mobEnd;
	
private:


	float timer;
};

#endif // !