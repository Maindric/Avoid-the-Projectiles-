#include "Character.h"
#include "string.h"
#include <fstream>

void Character::Setup()
{
	image = agk::LoadImage("media\\Character.png");
	std::ifstream stream("media\\animationnames.txt");
	std::string bufferString;

	//Cycle through the images to load them.
	for (int i = 0; i < 128; i++)
	{
		//Only load the image if it exists.
		if (std::getline(stream, bufferString))
		{
			spriteImg[i] = agk::LoadSubImage(image, bufferString.c_str());
		}
	}

	sprite = agk::CreateSprite(0);

	agk::AddSpriteAnimationFrame(sprite, spriteImg[0]);
	agk::AddSpriteAnimationFrame(sprite, spriteImg[16]);
	agk::AddSpriteAnimationFrame(sprite, spriteImg[32]);
	agk::AddSpriteAnimationFrame(sprite, spriteImg[48]);

	/*
	anim["idle_D"] = Animation(1, 1, 1);
	anim["idle_R"] = Animation(1, 2, 2);
	anim["idle_L"] = Animation(1, 3, 3);
	anim["idle_U"] = Animation(1, 4, 4);
	*/

	anim.insert(std::make_pair("idle_D", Animation(1, 1, 1)));
	anim.insert(std::make_pair("idle_R", Animation(1, 2, 2)));
	anim.insert(std::make_pair("idle_L", Animation(1, 3, 3)));
	anim.insert(std::make_pair("idle_U", Animation(1, 4, 4)));

	SetFacingDirection(Direction::Dir::Left);

	agk::SetSpritePosition(sprite, 200, 200);
}

void Character::SetFacingDirection(Direction::Dir dir)
{
	switch (dir)
	{
	case Direction::Dir::Down:
		agk::PlaySprite(sprite, anim["idle_D"].GetSpeed(), 1, anim["idle_D"].GetStartFrame(), anim["idle_D"].GetEndFrame());
		break;
	case Direction::Dir::Right:
		agk::PlaySprite(sprite, anim["idle_R"].GetSpeed(), 1, anim["idle_R"].GetStartFrame(), anim["idle_R"].GetEndFrame());
		break;
	case Direction::Dir::Left:
		agk::PlaySprite(sprite, anim["idle_L"].GetSpeed(), 1, anim["idle_L"].GetStartFrame(), anim["idle_L"].GetEndFrame());
		break;
	case Direction::Dir::Up:
		agk::PlaySprite(sprite, anim["idle_U"].GetSpeed(), 1, anim["idle_U"].GetStartFrame(), anim["idle_U"].GetEndFrame());
		break;
	}
}

void Character::Update(float t)
{
	if (agk::GetJoystickX() < 0)
	{
		SetFacingDirection(Direction::Dir::Left);
	}
	if (agk::GetJoystickX() > 0)
	{
		SetFacingDirection(Direction::Dir::Right);
	}
	if (agk::GetJoystickY() < 0)
	{
		SetFacingDirection(Direction::Dir::Up);
	}
	if (agk::GetJoystickY() > 0)
	{
		SetFacingDirection(Direction::Dir::Down);
	}
	agk::SetSpritePosition(sprite, agk::GetSpriteX(sprite) + (agk::GetJoystickX() * t * 150),
								   agk::GetSpriteY(sprite) + (agk::GetJoystickY() * t * 150));
}