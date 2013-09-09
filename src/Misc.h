#ifndef __MISC__
#define __MISC__
#include <sstream>
template <class T>
T FromString(std::string s) {
	T result;
	std::stringstream str;
	str << s;
	str >> result;
	return result;
}
template <class T>
std::string ToString(T d) {
	std::string s;
	std::stringstream str;
	str << d;
	str >> s;
	return s;
}
#endif

