#include "template.h"

class Time
{
	float cur_frame_time;
	float last_frame_time;
	float cur_frame_dif;
	float start_time;
public:
	void Setup();
	void Update();
	float GetCurrentFrameTime();
	float GetUpdateTime();
	float GetTotalTime();
};