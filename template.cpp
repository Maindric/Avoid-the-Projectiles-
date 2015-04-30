// Includes
#include "template.h"
#include "Background.h"
#include "Character.h"

// Namespace
using namespace AGK;

app App;

Background background;
Character character;

void app::Begin(void)
{
	agk::SetWindowTitle("Avoud the stuff");
	agk::SetWindowSize(1280, 720, 0);
	agk::SetVirtualResolution(1280, 720);
	agk::SetSyncRate(60, 0);
	agk::EnableClearColor(0);
	agk::SetScissor(0, 0, 0, 0);

	background.CreateBackground();
	character.SetUp(0);
}

void app::Loop (void)
{

	if (agk::GetJoystickX() < 0)
	{
		character.SetFacingDirection(Direction::Left);
	}
	if (agk::GetJoystickX() > 0)
	{
		character.SetFacingDirection(Direction::Right);
	}
	if (agk::GetJoystickY() < 0)
	{
		character.SetFacingDirection(Direction::Up);
	}
	if (agk::GetJoystickY() > 0)
	{
		character.SetFacingDirection(Direction::Down);
	}

	character.Update();

	agk::Print(agk::ScreenFPS());
	agk::PrintC("X: ");
	agk::Print(agk::Str(agk::GetJoystickX()));
	agk::PrintC("Y: ");
	agk::Print(agk::Str(agk::GetJoystickY()));
	agk::Sync();

}


void app::End (void)
{

}
