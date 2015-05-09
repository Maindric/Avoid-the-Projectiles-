/*
Honestly, this class should likely be replaced with a struct.
*/
#include "AnimationTypes.h"

class Animation
{
	float speed;
	int startFrame;
	int endFrame;
public:
	Animation();
	Animation(float spd, int firstFrame, int lastFrame);
	int GetStartFrame();
	int GetEndFrame();
	float GetSpeed();
};