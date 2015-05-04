#include "Text.h"

/*
Text::Text(std::string textImage)
{
	image = agk::LoadImage((char*)textImage.c_str());
	agkText = agk::CreateText("Hello World!");
	agk::SetTextFontImage(agkText, image);
	agk::SetTextSize(agkText, 24);
}
*/

void Text::Setup(std::string textImage)
{
	image = agk::LoadImage((char*)textImage.c_str());
	agkText = agk::CreateText("Hello World!");
	agk::SetTextFontImage(agkText, image);
	agk::SetTextSize(agkText, 24);
}

void Text::SetText(std::string setText)
{
	text = setText;
	agk::SetTextString(agkText, (char*)text.c_str());
}