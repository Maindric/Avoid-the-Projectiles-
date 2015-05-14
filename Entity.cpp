#include "Entity.h"
#include "template.h"

int Entity::count = 0;

Entity::Entity()
{
	count++;

	int rng = agk::Random(1, 1000);
	if (rng == 1)
	{
		sprite = agk::CreateSprite(agk::LoadImage("media\\Henry.png"));
	}
	else
	{
		sprite = agk::CreateSprite(agk::LoadImage("media\\Arrow.png"));
	}

	agk::SetSpriteScale(sprite, 2.5, 2.5);
	agk::SetSpriteShape(sprite, 3);
	Generate(130 + count, 200 + count);

	int randInt = agk::Random(0, 3);
	switch (randInt)
	{
	case 0:
		direction = Direction::Dir::Down;
		pos_y = -16;
		pos_x = agk::Random(7, 1273);
		agk::SetSpriteAngle(sprite, 180);
		break;

	case 1:
		direction = Direction::Dir::Right;
		pos_x = -16;
		pos_y = agk::Random(7, 713);
		agk::SetSpriteAngle(sprite, 90);
		break;

	case 2:
		direction = Direction::Dir::Left;
		pos_x = 1296;
		pos_y = agk::Random(7, 1273);
		agk::SetSpriteAngle(sprite, -90);
		break;

	case 3:
		direction = Direction::Dir::Up;
		pos_y = 736;
		pos_x = agk::Random(7, 1273);
		break;
	}
}

void Entity::Generate(int low_speed, int hi_speed)
{
	speed = agk::Random(low_speed, hi_speed);
}

void Entity::Update(float time)
{
	switch (direction)
	{
	case Direction::Dir::Down:
		pos_y += speed * time;
		break;
	case Direction::Dir::Right:
		pos_x += speed * time;
		break;
	case Direction::Dir::Up:
		pos_y -= speed * time;
		break;
	case Direction::Dir::Left:
		pos_x -= speed * time;
		break;
	}

	agk::SetSpritePosition(sprite, pos_x, pos_y);
}


int Entity::GetSprite()
{
	return sprite;
}

int Entity::GetCount()
{
	return count;
}

int Entity::GetSpriteX()
{
	return agk::GetSpriteX(sprite);
}

int Entity::GetSpriteY()
{
	return agk::GetSpriteY(sprite);
}

void Entity::Delete()
{
	agk::DeleteSprite(sprite);
}

void Entity::ResetCount()
{
	count = 0;
}