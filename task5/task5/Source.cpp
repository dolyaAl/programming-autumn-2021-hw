#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<list>

using namespace std;

template <class T>
void print(const T& cont)
{
	for (auto i = cont.begin(); i != cont.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

template <class T>
void enlarge(T& cont)
	{
		for (auto i = cont.begin(); i != cont.end(); ++i)
		{
			auto a = *i;
			++i;
			if (i == cont.end())
			{
				return;
			}
			auto b = *i;
			i = cont.insert(i, (a + b) / 2);
		}
	}

template <class T>
void del(T& cont)
{
	auto i = cont.begin();
	i++;
	for (i;i != cont.end(); ++i)
	{
		i = cont.erase(i);
		if (i == cont.end())
		{
			return;
		}
	}
}

template <class T>
T concat(T& first, T& second)
{
	T cont(first.size() + second.size());
	copy(first.begin(), first.end(), cont.begin());
	auto i = cont.begin();
	for (unsigned int j = 0; j < first.size(); ++j)
	{
		i++;
	}
	copy(second.begin(), second.end(), i);

	return cont;
}

template <class T>
T repeat(unsigned int n, T& source)
{
	T cont;
	for (unsigned int i = 0; i < n; ++i)
	{
		cont = concat(cont, source);
	}
	return cont;
}

template <class T>
auto find_second_in(int n, const T& source)
{
	auto i = find(source.begin(), source.end(), n);
	i++;
	i = find(i, source.end(), n);
	return i;
}

template <class T>
auto find_last_in(int n, const T& source)
{
	auto i = find(source.begin(), source.end(), n);
	auto j = i;
	for (unsigned int k = 0; k < source.size() && i != source.end(); ++k)
	{
		++i;
		if (find(i, source.end(), n) != source.end())
		{
			j = find(i, source.end(), n);
		}
	}
	return j;
}

template <class T>
bool subseq(const T& main, const T& sub)
{
	auto j = main.begin();
	for (auto i = sub.begin(); i != sub.end(); i++)
	{
		j = find(j, main.end(), *i);
		if (j == main.end())
		{
			return false;
		}
		j++;
	}
	return true;
}

void func(vector<double>& v, double& x, double& i, double& j)
{
	vector<double>::iterator k;
	vector<double>::iterator n;
	int index = 0;
	k = lower_bound(v.begin(), v.end(), x);
	if (k != v.end() && *k == x)
	{
		for (n = v.begin(); n != k; ++n)
		{
			index++;
		}
		i = index;
		j = index;
	}
	else
	{
		if (i == j)
		{
			++i;
		}
	}
}

int main()
{
	vector<double> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	print(v);
	enlarge(v);
	print(v);
	del(v);
	print(v);

	unsigned int arr_size = v.size();
	double* arr = new double[arr_size];
	copy(v.begin(), v.end(), arr);
	for (unsigned int i = 0; i < arr_size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	vector<double> v3 = repeat(3, v);
	print(v3);

	auto i = find_second_in(3, v3);
	if (i != v3.end())
	{
		cout << *i << endl;
	}

	i = find_last_in(3, v3);
	if (i != v3.end())
	{
		cout << *i << endl;
	}

	vector<double> v2(3, 1);
	cout << subseq(v3, v2) << endl;

	sort(v3.begin(), v3.end());
	print(v3);
	double x = 1;
	double a = 5;
	double b = 5;
	func(v3, x, a, b);
	cout << a << " " << b << endl;


	return EXIT_SUCCESS;
}