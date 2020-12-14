#pragma once
#include <exception>
class stack_exception : public std::exception {

public:
	stack_exception(char const* const message = "overflow") :exception() {
	};

};
