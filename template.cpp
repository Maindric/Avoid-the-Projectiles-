// Includes
#include "template.h"
#include "Direction.h"
#include "Text.h"
#include "string.h"
#include "Entity.h"
#include "Background.h"
#include "Character.h"
#include "Button.h"
#include "Time.h"
#include "Audio.h"
#include "Score.h"
#include <vector>

// Namespace
using namespace AGK;

app App;

Background bg;
Time t;

Text fpsDisplay;
Text scoreDisplay;
Text highScoreDisplay;
Character Player;
Audio arrowAudio;
Score score;

std::vector<Entity> Entities;

Button button;
int box;

void Game();
void MainMenu();
void SetupGame();
void SetupMenu();

int gameState = 0;

void app::Begin(void)
{
	agk::SetWindowTitle("Steve and Henry");
	agk::SetVirtualResolution(1280, 720);
	agk::SetSyncRate(60, 0);
	agk::EnableClearColor(0);
	agk::SetScissor(0, 0, 0, 0);


	arrowAudio.Setup();
	score.Setup();

	SetupMenu();
}

void app::Loop (void)
{
	fpsDisplay.SetText(String::to_string(agk::ScreenFPS()));
	highScoreDisplay.SetText("High Score: " + String::to_string(score.GetHighScore()));
	switch (gameState)
	{
	case 0:
		MainMenu();
		break;
	case 1:
		Game();
		break;
	}


	//If ESC is pressed, exit the app.
	if (agk::GetRawKeyState(27))
	{
		exit(0);
	}
}


void app::End (void)
{
}


void Game()
{
	t.Update();

	if (agk::Random(0, 99) <= (240 + Entity::GetCount()) * t.GetUpdateTime())
	{
		Entities.push_back(Entity());
		arrowAudio.PlayClip();
	}

	for (int i = 0; i < Entities.size(); i++)
	{
		if (agk::GetSpriteCollision(Player.GetSprite(), Entities[i].GetSprite()))
		{
			score.SubmitScore(t.GetTotalTime());
			gameState = 0;
			Entities.clear();
			agk::DeleteAllSprites();
			agk::DeleteAllImages();
			SetupMenu();
			Entity::ResetCount();
			return;
		}
		Entities[i].Update(t.GetUpdateTime());
		if (Entities[i].GetSpriteX() < -32 ||
			Entities[i].GetSpriteX() > 1312 ||
			Entities[i].GetSpriteY() < -32 ||
			Entities[i].GetSpriteY() > 752)
		{
			Entities[i].Delete();
			Entities.erase(Entities.begin() + i);
			i--;
		}
	}

	scoreDisplay.SetText("Score: " + String::to_string(t.GetTotalTime()));

	Player.Update(t.GetUpdateTime());

	agk::Sync();
}

void MainMenu()
{
	button.update();
	if (button.IsPressed())
	{
		agk::DeleteAllSprites();
		agk::DeleteAllImages();
		gameState = 1;
		SetupGame();
	}
	agk::Sync();
}

void SetupGame()
{
	highScoreDisplay.Setup();
	highScoreDisplay.SetPosition(1000, 10);
	fpsDisplay.Setup();
	scoreDisplay.Setup();
	scoreDisplay.SetPosition(520, 10);
	bg.CreateBackground();
	Player.Setup();
	t.Setup();
}

void SetupMenu()
{
	highScoreDisplay.Setup();
	highScoreDisplay.SetPosition(1000, 10);
	fpsDisplay.Setup();
	bg.CreateBackground();
	box = agk::CreateSprite(agk::LoadImage("media\\UI_BG.png"));
	agk::SetSpritePosition(box, 364, 104);
	button.setup();
}