#include "template.h"
#include "Direction.h"

class Entity
{
	float pos_x;
	float pos_y;
	int sprite;
	int speed;
	Direction::Dir direction;
public:
	void Setup();
	void Generate(int low_speed, int hi_speed);
	void Update(float time);
};