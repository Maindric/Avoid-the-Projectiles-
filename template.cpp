// Includes
#include "template.h"
#include "Character.h"
#include "Direction.h"
#include "Text.h"
#include "string.h"
#include "Entity.h"
#include "Background.h"
#include "Time.h"

// Namespace
using namespace AGK;

app App;

Background background;
Time t;

Text fpsDisplay;
Character Player;

Entity testEnt;

void app::Begin(void)
{
	agk::SetWindowTitle("Avoid the stuff");
	agk::SetVirtualResolution(1280, 720);
	agk::SetSyncRate(60, 0);
	agk::EnableClearColor(0);
	agk::SetScissor(0, 0, 0, 0);

	background.CreateBackground();

	fpsDisplay.Setup();

	Player.Setup();

	t.Setup();

	testEnt.Setup();
	testEnt.Generate(60,80);
}

void app::Loop (void)
{
	t.Update();

	//If ESC is pressed, exit the app.
	if (agk::GetRawKeyState(27))
	{
		exit(0);
	}

	testEnt.Update(t.GetUpdateTime());

	fpsDisplay.SetText(String::to_string(agk::ScreenFPS()));

	Player.Update(t.GetUpdateTime());

	agk::Sync();

}


void app::End (void)
{
}
