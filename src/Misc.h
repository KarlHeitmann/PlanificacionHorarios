#ifndef __MISC__
#define __MISC__
#include <sstream>
template <class T>
class Misc {
	public:
		T FromString(std::string);
		std::string ToString(T);
};
#endif

