#include <iostream>
#include "Sub.h"
#include <list>

using namespace std;

void print_menu()
{
	char menu[512] ={
		"+--------------------------+\n"
		"|           MENU           |\n"
		"+--------------------------+\n"
		"|1. Add sub to list        |\n"
		"+--------------------------+\n"
        "|2. Del sub from list      |\n"
		"+--------------------------+\n"
		"|3. Print sub              |\n"
		"+--------------------------+\n"
		"|4. EXIT                   |\n"
		"+--------------------------+\n"};

	cout << menu;
}
void menu_error(int x)
{
	cout << "POINT: " << x << " IS INCORRECT. TRY AGAIN..." << endl;
}
void add_sub(list<Sub>& l)
{
	Sub s;
	cout << "Enter subscriber's phone number, name and address: " << endl;
	cin >> s;
	l.push_back(s);
}
void del_sub(list<Sub>& l)
{
	Sub s;
	char num[30]{ 0 };
	cin >> num;
	int count = 30;
	list<Sub>::iterator i;
	for (i = l.begin(); i != l.end(); ++i)
	{
		s = *i;
		for (int j = 0; j < 30 && count == 30; ++j)
		{
			if (s.ph_num[j] != num[j])
			{
				--count;
			}
		}
		if (count == 30)
		{
			i = l.erase(i);
		}
		count = 30;
	}
}
void print_sub(list<Sub>& l)
{
	Sub s;
	char num[30]{ 0 };
	int count = 30;
	cin >> num;
	list<Sub>::iterator i;
	for (i = l.begin(); i != l.end(); ++i)
	{
		s = *i;
		for (int j = 0; j < 30 && count == 30; ++j)
		{
			if (s.ph_num[j] != num[j])
			{
				--count;
			}
		}
		if (count == 30)
		{
			cout << s << endl;
		}
		count = 30;
	}
}

ostream& operator<< (ostream& st, list<Sub> l)
{
	Sub s;
	list<Sub>::iterator i;
	for (i = l.begin(); i != l.end(); ++i)
	{
		s = *i;
		st << s << endl;
	}
	return st;
}
istream& operator>> (istream& st, list<Sub>& l)
{
	Sub s;
	list<Sub>::iterator i;
	while (st >> s)
	{
		l.push_back(s);
	}
	return st;
}

int main()
{
	list<Sub> l;
	int x = 0;
	bool working = true;

	while (working)
	{
		print_menu();
		cin >> x;
		switch (x)
		{
		case 1:
		{
			add_sub(l);
			break;
		}
		case 2:
		{
			del_sub(l);
			break;
		}
		case 3:
		{
			print_sub(l);
			break;
		}
		case 4:
		{
			working = false;
			break;
		}
		default:
		{
			menu_error(x);
			break;
		}
		}
	}

	cout << l;

	return EXIT_SUCCESS;
}