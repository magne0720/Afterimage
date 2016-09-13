#include "Umbrella.h"

bool Umbrella::init()
{
	if (!Sprite::init())
	{
		return false;
	}





	return true;
}
void Umbrella::randomMan()
{
	this->initWithFile("PlantNot1.png");

	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> (100, 102);



}