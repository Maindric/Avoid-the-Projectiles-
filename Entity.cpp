#include "Entity.h"

void Entity::Setup()
{
	sprite = agk::CreateSprite(agk::LoadImage("media\\Arrow.png"));
	direction = Direction::Dir::Right;
	agk::SetSpriteAngle(sprite, 90);
	pos_x = 0;
	pos_y = 350;
	agk::SetSpriteScale(sprite, 2, 2);
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
		pos_y += speed * time * -1;
		break;
	case Direction::Dir::Left:
		pos_x += speed * time * -1;
	}

	agk::SetSpritePosition(sprite, pos_x, pos_y);
}