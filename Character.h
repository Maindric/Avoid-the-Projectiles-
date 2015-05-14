#include "template.h"
#include "Direction.h"
#include "Animation.h"
#include <map>
#include <string>

class Character
{
	int sprite;
	int spriteImg[128];
	int image;
	Direction::Dir facingDir;
	std::map<std::string, Animation> anim;
	bool moving;
public:
	void Setup();
	void Update(float t);
	void MoveCaracter(float speed);
	void SetFacingDirection(Direction::Dir dir);
	int GetSprite();
	void Destroy();
};