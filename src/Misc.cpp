#include <sstream>
#include "Misc.h"
template <class T>
T Misc<T>::FromString(std::string s) {
	T result;
	std::stringstream str;
	str << s;
	str >> result;
	return result;
}
template <class T>
std::string Misc<T>::ToString(T d) {
	std::string s;
	std::stringstream str;
	str << d;
	str >> s;
	return s;
}
