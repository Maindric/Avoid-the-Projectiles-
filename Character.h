#include "Vector.h"
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
	Vector position;
	Direction facingDirection;
	std::map <std::string, Animation> Animations;
public:
	void Update()
	{
		if (agk::GetSpriteImageID(sprite) != atlasImages[facingDirection])
		{
			agk::SetSpriteImage(sprite, atlasImages[facingDirection]);
		}

	}
	void MoveCaracter(float speed);
	void SetFacingDirection(Direction dir)
	{
		facingDirection = dir;
	}
	void SetUp(int outline)  //1 = outline, 0 = no outline
	{
		image = agk::LoadImage("media//character.png");
		int file = agk::OpenToRead("media//animation names.txt");
		for (int i = 0; i < 128; i++)
		{
			if (outline == 1)
			{
				//NOTE: I need to find a way to add "_O" to the end of agk::ReadString() to get this to work.
			}
			else
			{
				atlasImages[i] = agk::LoadSubImage(image, agk::ReadString(file));
			}
		}
		agk::CloseFile(file);
		sprite = agk::CreateSprite(atlasImages[0]);
		SetFacingDirection(Direction::Down);
		agk::SetSpritePosition(sprite, 50.0f, 50.0f);

		//Set up animations.

	};
};