#include "template.h"
#include "Direction.h"
#include "Animation.h"

class Character
{
	int sprite;
	int image;
	int atlasImages[128];
public:
	void Setup();
	void Update();
	void MoveCaracter(float speed);
	void SetFacingDirection();
};