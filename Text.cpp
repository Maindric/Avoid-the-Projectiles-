#include "Text.h"

#ifdef __cplusplus
extern "C" {
#endif

	unsigned int Text::defaultImage = 0;

	void Text::Setup()
	{
		if (defaultImage == 0)
		{
			defaultImage = agk::LoadImage("media\\Font\\Hammersmith One.png");
		}
		agkText = agk::CreateText("Hello World!");
		agk::SetTextFontImage(agkText, defaultImage);
		agk::SetTextSize(agkText, 18);
	}

	void Text::Setup(std::string textImage)
	{
		image = agk::LoadImage((char*)textImage.c_str());
		agkText = agk::CreateText("Hello World!");
		agk::SetTextFontImage(agkText, image);
		agk::SetTextSize(agkText, 18);
	}

	void Text::SetText(std::string setText)
	{
		text = setText;
		agk::SetTextString(agkText, (char*)text.c_str());
	}

	void Text::SetPosition(float x, float y)
	{
		agk::SetTextPosition(agkText, x, y);
	}

#ifdef __cplusplus
}
#endif