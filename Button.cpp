#include "Button.h"
#include "template.h"

void Button::setup()
{
	sprite = agk::CreateSprite(0);
	agk::AddSpriteAnimationFrame(sprite, agk::LoadImage("media\\button\\Default.png"));
	agk::AddSpriteAnimationFrame(sprite, agk::LoadImage("media\\button\\Highlight.png"));
	agk::AddSpriteAnimationFrame(sprite, agk::LoadImage("media\\button\\Pressed.png"));
	agk::PlaySprite(sprite, 1, 1, 1, 1);

	agk::SetSpritePosition(sprite, 512, 296);
}

void Button::update()
{
	if (agk::GetSpriteHit(agk::GetPointerX(), agk::GetPointerY()) == sprite)
	{
		state = 1;
		agk::PlaySprite(sprite, 1, 1, 2, 2);
		if (agk::GetPointerState() == 1)
		{
			state = 2;
			agk::PlaySprite(sprite, 1, 1, 3, 3);
			mouseOver = true;
		}
		else if (mouseOver)
		{
			state = 3;
			mouseOver = false;
		}
	}
	else
	{
		mouseOver = false;
		state = 0;
		agk::PlaySprite(sprite, 1, 1, 1, 1);
	}
}

bool Button::IsPressed()
{
	if (state == 3)
	{
		return true;
	}
	return false;
}