#include "Animation.h"

Animation::Animation()
{
	speed = 1;
}

Animation::Animation(float spd, int firstFrame, int lastFrame)
{
	speed = spd;
	startFrame = firstFrame;
	endFrame = lastFrame;
}

int Animation::GetStartFrame()
{
	return startFrame;
}

int Animation::GetEndFrame()
{
	return endFrame;
}

float Animation::GetSpeed()
{
	return speed;
}