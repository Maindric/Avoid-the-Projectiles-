#include "Character.h"

void Character::Setup()
{
	image = agk::LoadImage("media\\Character.png");
	sprite = agk::CreateSprite(image);

}