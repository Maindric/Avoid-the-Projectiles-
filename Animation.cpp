#include "Animation.h"

void Animation::Setup(float spd, int firstFrame, int lastFrame)
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