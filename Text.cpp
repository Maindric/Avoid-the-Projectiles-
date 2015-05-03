#include "Text.h"

Text::Text(void)
{
	agkText = agk::CreateText("Hello World!");
	if (defaultImage == 0)
	{
		defaultImage = agk::LoadImage("media/Font/Hammersmith One.png");
	}
	agk::SetTextFontImage(agkText, defaultImage);
	agk::SetTextSize(agkText, 24);
}

Text::Text(std::string textImage)
{
	agkText = agk::CreateText("Hello World!");
	image = agk::LoadImage((char*)textImage.c_str());
	agk::SetTextFontImage(agkText, image);
}

void Text::SetText(std::string setText)
{
	text = (char*)setText.c_str();
}

void Text::SetDefaultFont(int fontImg)
{
	defaultImage = fontImg;
}