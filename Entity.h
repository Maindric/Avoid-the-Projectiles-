#include "Direction.h"

class Entity
{
	static int count;
	float pos_x;
	float pos_y;
	int sprite;
	int speed;
	Direction::Dir direction;
public:
	Entity();
	static void Setup();
	void Generate(int low_speed, int hi_speed);
	void Update(float time);
	int GetSprite();
	int GetSpriteX();
	int GetSpriteY();
	void Delete();
	static int GetCount();
	static void ResetCount();
};