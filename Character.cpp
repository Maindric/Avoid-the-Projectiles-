#include "Character.h"
#include "string.h"
#include <fstream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

void Character::Setup()
{
	moving = false;

	//These are initializations for lines to initiate animation support.
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

	stream.close();

	//agk::CreateSprite(0) makes and empty sprite for editing.
	sprite = agk::CreateSprite(0);

	//Initalize all the needed variable to set up the animations.
	std::ifstream animationsStream("media\\characteranimations.txt");
	std::vector<std::string> animationData;
	char letter;
	int dataSect = 0;
	int animationStart = 0;
	int animationEnd = 0;

	
	//This loop lasts for however many lines are included in the animations file.
	//Each line is written as follows:
	//(Animation Name),(Sprite Frame For Animation 1), (Sprite Frame For Animation 2), etc...
	//TO ADD: * in front of animation name to symbolize no facing direction.
	for (int i = 1; std::getline(animationsStream, bufferString); i++)
	{
		animationData.push_back("");
		for (int j = 0; j < bufferString.length(); j++)
		{
			letter = bufferString.at(j);
			if (letter == ',')
			{
				dataSect++;
				animationData.push_back("");
			}
			else if (letter != '\n')
			{
				animationData[dataSect] += letter;
			}
		}
		
		//j = facing direction to load.
		//j = 0 Down; j = 1 Right; j = 2 Left; j = 3 Down
		for (int j = 0; j < 4; j++)
		{
			animationStart = animationEnd + 1;
			for (int k = 1; k < animationData.size(); k++)
			{
				agk::AddSpriteAnimationFrame(sprite, spriteImg[std::atoi(animationData[k].c_str()) + (j * 16)]);
				animationEnd++;
			}
			switch (j)
			{
			case 0:
				anim.insert(std::make_pair(animationData[0] + "_D", Animation(7, animationStart, animationEnd)));
				break;
			case 1:
				anim.insert(std::make_pair(animationData[0] + "_R", Animation(7, animationStart, animationEnd)));
				break;
			case 2:
				anim.insert(std::make_pair(animationData[0] + "_L", Animation(7, animationStart, animationEnd)));
				break;
			case 3:
				anim.insert(std::make_pair(animationData[0] + "_U", Animation(7, animationStart, animationEnd)));
				break;
			}
		}

		//These need to be cleared each line to ensure animations are loaded properly.
		animationData.clear();
		dataSect = 0;
	}

	//This will be edited. Just ensure the player is set up fine.
	SetFacingDirection(Direction::Dir::Down);
	agk::SetSpritePosition(sprite, 200, 200);
	agk::SetSpriteScale(sprite, 2, 2);
	agk::SetSpriteShape(sprite, 3);
}

void Character::SetFacingDirection(Direction::Dir dir)
{
	//Play the run animation depending on where the player is facing.
	facingDir = dir;
	switch (dir)
	{
	case Direction::Dir::Down:
		agk::PlaySprite(sprite, anim["run_D"].GetSpeed(), 1, anim["run_D"].GetStartFrame(), anim["run_D"].GetEndFrame());
		break;
	case Direction::Dir::Right:
		agk::PlaySprite(sprite, anim["run_R"].GetSpeed(), 1, anim["run_R"].GetStartFrame(), anim["run_R"].GetEndFrame());
		break;
	case Direction::Dir::Left:
		agk::PlaySprite(sprite, anim["run_L"].GetSpeed(), 1, anim["run_L"].GetStartFrame(), anim["run_L"].GetEndFrame());
		break;
	case Direction::Dir::Up:
		agk::PlaySprite(sprite, anim["run_U"].GetSpeed(), 1, anim["run_U"].GetStartFrame(), anim["run_U"].GetEndFrame());
		break;
	}
}

void Character::Update(float t)
{
	//Check for input.
	if (agk::GetJoystickX() < 0)
	{
		//If the player is not facing the direction already OR the player stopped and continued walking again.
		if (facingDir != Direction::Dir::Left || moving == false)
		{
			SetFacingDirection(Direction::Dir::Left);
		}
		moving = true;
	} 
	else if (agk::GetJoystickX() > 0)
	{
		//If the player is not facing the direction already OR the player stopped and continued walking again.
		if (facingDir != Direction::Dir::Right || moving == false)
		{
			SetFacingDirection(Direction::Dir::Right);
		}
		moving = true;
	}
	else if (agk::GetJoystickY() < 0)
	{
		//If the player is not facing the direction already OR the player stopped and continued walking again.
		if (facingDir != Direction::Dir::Up || moving == false)
		{
			SetFacingDirection(Direction::Dir::Up);
		}
		moving = true;
	}
	else if (agk::GetJoystickY() > 0)
	{
		//If the player is not facing the direction already OR the player stopped and continued walking again.
		if (facingDir != Direction::Dir::Down || moving == false)
		{
			SetFacingDirection(Direction::Dir::Down);
		}
		moving = true;
	}
	else
	{
		//If the player stops walking, switch to the idle animation.
		switch (facingDir)
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
		moving = false;
	}
	//Move the player. This movement system has the problem where diagnal movement is faster than straight.
	agk::SetSpritePosition(sprite, agk::GetSpriteX(sprite) + (agk::GetJoystickX() * t * 200),
								   agk::GetSpriteY(sprite) + (agk::GetJoystickY() * t * 200));

	if (agk::GetSpriteX(sprite) < 16)
	{
		agk::SetSpriteX(sprite, 16);
	}
	else if (agk::GetSpriteX(sprite) > 1225)
	{
		agk::SetSpriteX(sprite, 1225);
	}
	if (agk::GetSpriteY(sprite) < 16)
	{
		agk::SetSpriteY(sprite, 16);
	}
	else if (agk::GetSpriteY(sprite) > 650)
	{
		agk::SetSpriteY(sprite, 650);
	}
}


int Character::GetSprite()
{
	return sprite;
}

void Character::Destroy()
{
	agk::DeleteSprite(sprite);
	agk::DeleteImage(image);
	for (int i = 0; i < 128; i++)
	{
		agk::DeleteImage(spriteImg[i]);
	}
}
