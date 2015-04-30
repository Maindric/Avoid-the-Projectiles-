#include "template.h"

class Background
{
	int spriteNumber;
public:
	void CreateBackground()
	{
		int image = agk::LoadImage("media//background.png");
		spriteNumber = agk::CreateSprite(image);
	};
	int GetSpriteNumber()
	{
		return spriteNumber;
	};
};