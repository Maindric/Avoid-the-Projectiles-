#include "template.h"
#include <string>

#ifdef __cplusplus
extern "C" {
#endif

	class Text
	{
		static unsigned int defaultImage;
		unsigned int image;
		unsigned int agkText;
		std::string text;
	public:
		void Setup();
		void Setup(std::string textImage);
		void SetText(std::string setText);
		void SetPosition(float x, float y);
	};

#ifdef __cplusplus
}
#endif