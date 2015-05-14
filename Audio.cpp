#include "template.h"
#include "Audio.h"

void Audio::Setup()
{
	audio = agk::LoadSound("media\\arrow.wav");
	music = agk::LoadMusic("media\\Music.wav");
	agk::PlayMusic(music, 1);
}

void Audio::PlayClip()
{
	agk::PlaySound(audio);
}