#ifndef __DELEGATE_CHANGER_H__
#define __DELEGATE_CHANGER_H__

#include "cocos2d.h"
#include "MapTestScene.h"




USING_NS_CC;




class DelegateChanger :public Scene
{
public:
	CREATE_FUNC(DelegateChanger);
	bool init();
	void update(float delta); [
	@]

	int sceneNumber;
	Vector<Scene*> Scenes;
	Scene* ChangeScene(Scene &target);

};



#endif // !__DELEGATE_CHANGER_H__
