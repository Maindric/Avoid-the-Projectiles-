#include "template.h"

class Time
{
	float cur_frame_time;
	float last_frame_time;
	float cur_frame_dif;
public:
	void Setup();
	void Update();
	float GetCurrentFrameTime();
	float GetUpdateTime();
};