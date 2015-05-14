#include <string>
#include <sstream>

class String
{
public:
	template <typename T>
	static std::string to_string(T value)
	{
		std::ostringstream os;
		os << value;
		return os.str();
	};

	template <typename T>
	static T StringToNumber(const std::string &Text)//Text not by const reference so that the function can be used with a 
	{                               //character array as argument
		std::stringstream ss(Text);
		T result;
		return ss >> result ? result : 0;
	};
};