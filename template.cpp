// Includes
#include "template.h"
#include "Background.h"
#include "Character.h"
#include "Direction.h"
#include "Text.h"
#include <string>

// Namespace
using namespace AGK;

app App;

Background background;
Text fpsDisplay;
Text height;
Text width;
Character Player;

void app::Begin(void)
{
	agk::SetWindowTitle("Avoid the stuff");
	agk::SetVirtualResolution(1280, 720);
	agk::SetSyncRate(60, 0);
	agk::EnableClearColor(0);
	agk::SetScissor(0, 0, 0, 0);

	background.CreateBackground();

	fpsDisplay.Setup();
	height.Setup();
	width.Setup();

	width.SetText("Width: " + std::to_string(agk::GetDeviceWidth()));
	width.SetPosition(0.0f, 24.0f);
	height.SetText("Height: " + std::to_string(agk::GetDeviceHeight()));
	height.SetPosition(0.0f, 48.0f);

	Player.Setup();
}

void app::Loop (void)
{

	//If ESC is pressed, exit the app.
	if (agk::GetRawKeyState(27))
	{
		exit(0);
	}

	fpsDisplay.SetText(std::to_string(agk::ScreenFPS()));


	agk::Sync();

}


void app::End (void)
{
}
