#include "Score.h"
#include "template.h"
#include "string.h"

void Score::Setup()
{
	file = "Score.txt";

	int fileNum = agk::OpenToRead(file.c_str());
	highScore = agk::ReadFloat(fileNum);
	agk::CloseFile(fileNum);
}

void Score::SubmitScore(float subScore)
{
	if (subScore > highScore)
	{
		int fileNum = agk::OpenToWrite(file.c_str());
		agk::WriteFloat(fileNum, subScore);
		agk::CloseFile(fileNum);
		highScore = subScore;
	}
}

float Score::GetHighScore()
{
	return highScore;
}