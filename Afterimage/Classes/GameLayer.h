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

	//タッチ系
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	//モブがわく店
	void mobShop(int mobNum);
	void shopStopON(float delta);
	//Playerタイムロス
	void playerLoss(int mob);
	//プレイヤーが動けるように
	void lossRelease(float delta);
	//モブが振り返るまでの時間
	void mobLookBack(float delta);
	bool shopstop;         //モブ店湧きストッパー
	bool goalStop;         //連続ゴールストッパー
	bool hit();
	bool tapStop;          //タップストッパー
	bool actStop;          //初期入店演出防止


	/*Camera *camera;*/
	RainManager *rainManagerBack;
	RainManager *rainManager;
	Player *player;
	Sprite *spCamera;
	UmbrellaCreator *umbrella;
	MapCreator *map;
	//押し出しのアクション
	MoveBy *move;
	MoveBy *mobMove;
	
private:
	//歩く速さ
	float speed;
	//左か右か
	int leftAndRightNum;
	//モブの数
	int mobNum;
	//アクションストッパー
	bool ACTswitch;
	bool direction;
	//モブの怒りゲージ
	vector<int> angerGauge;
	vector<Sprite*> question;
	vector<Sprite*> anger;
};
#endif // !__GAME_LAYER_H__