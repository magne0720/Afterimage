#ifndef __RAIN_MANAGER_H__
#define __RAIN_MANAGER_H__

#include "cocos2d.h"
#include "MultiResolution.h"
#include <vector>
USING_NS_CC;
using namespace std;

class RainManager : public Node
{
public:
	static RainManager *create(int rainNum);
	bool init(int rainNum);
	
private:

};
#endif // !__RAIN_MANAGER_H__