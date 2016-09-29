#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"
#include "Player.h"
#include "MapCreator.h"
#include "MultiResolution.h"
#include "UmbrellaCreator.h"
#include "RainManager.h"
#include <vector>
using namespace std;

USING_NS_CC;

class GameLayer : public Layer
{
public:
	static GameLayer *create(int fromTitle);

	bool init(int fromTitle);

	int stageNum;
	int PlayerHP;
	void update(float delta);

	//�^�b�`�n
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	//���u���킭�X
	void mobShop(int mobNum);
	void shopStopON(float delta);
	//Player�^�C�����X
	void playerLoss();
	//�v���C���[��������悤��
	void lossRelease(float delta);
	//���u�X�N���X�g�b�p�[
	bool shopstop;
	//�A���S�[���X�g�b�p�[
	bool goalStop;
	bool hit();
	//�^�b�v�X�g�b�p�[
	bool tapStop;

	/*Camera *camera;*/
	RainManager *rainManagerBack;
	RainManager *rainManager;
	Player *player;
	Sprite *spCamera;
	UmbrellaCreator *umbrella;
	MapCreator *map;
	//�����o���̃A�N�V����
	MoveBy *move;
	
private:
	//��������
	float speed;
	//�����E��
	int leftAndRightNum;
	//���u�̐�
	int mobNum;
	//�A�N�V�����X�g�b�p�[
	bool ACTswitch;
	bool direction;
	//���u�̓{��Q�[�W
	vector<int> angerGauge;
};
#endif // !__GAME_LAYER_H__