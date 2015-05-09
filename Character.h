#include "template.h"
#include "Direction.h"
#include "Animation.h"
#include <map>
#include <string>

#ifdef __cplusplus
extern "C" {
#endif

	class Character
	{
		int sprite;
		int spriteImg[128];
		int image;
		std::map<std::string, Animation> anim;
	public:
		void Setup();
		void Update(float t);
		void MoveCaracter(float speed);
		void SetFacingDirection(Direction::Dir dir);
	};

#ifdef __cplusplus
}
#endif