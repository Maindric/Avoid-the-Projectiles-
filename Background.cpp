#include "Background.h"

void Background::CreateBackground()
{
	int image = agk::LoadImage("media\\background.png");
	spriteNumber = agk::CreateSprite(image);
}

int Background::GetSpriteNumber()
{
	return spriteNumber;
}