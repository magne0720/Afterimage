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
	//—~‚µ‚¢—Ê‚Ì‰J
	vector<Rain*> rain;
	bool init(int rainNum);
	//ˆÊ’uƒŠƒZƒbƒg
	void rainReset(Sprite *rain);
	void update(float delta);
	
private:
	//‰J‚Ì—Ê
	int rainOfRain;
	//‘¬‚³
	float speed;
};
#endif // !__RAIN_MANAGER_H__