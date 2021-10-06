#include "Sub.h"

std::ostream& operator<<(std::ostream& st, Sub s)
{
	st << "Subscriber " << s.name << std::endl << "Phone: " << s.ph_num << std::endl << "Address: " << s.address;
	return st;
}

std::istream& operator>>(std::istream& st, Sub& s)
{
	st >> s.ph_num >> s.name >> s.address;
	return st;
}
