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

void app::Begin(void)
{
	agk::SetWindowTitle("Avoid the stuff");
	agk::SetVirtualResolution(1280, 720);
	agk::SetSyncRate(60, 0);
	agk::EnableClearColor(0);
	agk::SetScissor(0, 0, 0, 0);

	background.CreateBackground();
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
