// Includes
#include "template.h"
#include "Background.h"
#include "Character.h"
#include "Direction.h"

// Namespace
using namespace AGK;

app App;

Background background;
int font;
int fpsDisplay;

void app::Begin(void)
{
	agk::SetWindowTitle("Avoid the stuff");
	agk::SetVirtualResolution(1280, 720);
	agk::SetSyncRate(60, 0);
	agk::EnableClearColor(0);
	agk::SetScissor(0, 0, 0, 0);

	background.CreateBackground();

	font = agk::LoadImage("media/Font/Hammersmith one.png");
	fpsDisplay = agk::CreateText("This is FPS:");
	agk::SetTextFontImage(fpsDisplay, font);
	agk::SetTextSize(fpsDisplay, 24);
	agk::SetTextColor(fpsDisplay, 255, 64, 64, 255);
	agk::SetTextPosition(fpsDisplay, 10, 10);
}

void app::Loop (void)
{

	//If ESC is pressed, exit the app.
	if (agk::GetRawKeyState(27))
	{
		exit(0);
	}

	agk::SetTextString(fpsDisplay, agk::Str(agk::ScreenFPS()));

	agk::Sync();

}


void app::End (void)
{

}
