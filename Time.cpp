#include "Time.h"

void Time::Setup()
{
	last_frame_time = agk::Timer();
	start_time = last_frame_time;
}

void Time::Update()
{
	cur_frame_time = agk::Timer();
	cur_frame_dif = cur_frame_time - last_frame_time;
	last_frame_time = cur_frame_time;
}

float Time::GetCurrentFrameTime()
{
	return cur_frame_time;
}

float Time::GetUpdateTime()
{
	return cur_frame_dif;
}

float Time::GetTotalTime()
{
	return cur_frame_time - start_time;
}