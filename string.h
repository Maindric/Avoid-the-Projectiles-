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
};