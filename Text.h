#include "template.h"
#include <string>

class Text
{
	static int defaultImage;

	int image;
	int agkText;
	std::string text;
public:
	Text(void);
	Text(std::string textImage);
	void SetText(std::string setText);
	static void SetDefaultFont(int fontImg);
};