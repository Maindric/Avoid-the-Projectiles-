#include "template.h"
#include "Direction.h"
#include "Animation.h"
#include <map>

enum AnimationName
{
	Idle = 1,
	Walk,
	HoldIdle,
	HoldWalk,
	Run,
	Jump,
	Fall,
	Nod,
	Shake,
	Blink
};

class Character
{
	int sprite;
	int image;
	int atlasImages[128];
public:
	void Update();
	void MoveCaracter(float speed);
	void SetFacingDirection();
	void SetUp(int outline);
};