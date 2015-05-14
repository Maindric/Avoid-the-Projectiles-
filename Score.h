#include <string>

class Score
{
	std::string file;
	float score;
	float highScore = 0;
public:
	void Setup();
	void SubmitScore(float subScore);
	float GetHighScore();
};