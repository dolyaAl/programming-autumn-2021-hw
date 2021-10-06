#pragma once
#include <iostream>

struct Sub
{
	char ph_num[30]{ 0 };
	char name[128]{ 0 };
	char address[128]{ 0 };
};

std::ostream& operator << (std::ostream& st, Sub s);
std::istream& operator >> (std::istream& st, Sub& s);
