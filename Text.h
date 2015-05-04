#include "template.h"
#include <string>

class Text
{
	unsigned int image;
	unsigned int agkText;
	std::string text;
public:
	//Text();
	//Text(std::string textImage);
	void Setup(std::string textImage);
	void SetText(std::string setText);
};