#pragma once
#include <exception>
using namespace std;

class fileErrors : public exception
{
public:
	virtual const char* what() const throw();
};

