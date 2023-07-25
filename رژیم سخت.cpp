#include <iostream>
using namespace std;
int main()
{

	int i, nr = 0, ny = 0;
	char array[5] = { 0 };
	for (i = 0; i < 5; i++)
	{
		cin >> array[i];

	}
	for (i = 0; i < 5; i++)
	{
		if (array[i] == 'R')
			nr++;
	}
	for (i = 0; i < 5; i++)
	{
		if (array[i] == 'Y')
			ny++;
	}
	if (nr >= 3 || (nr >= 2 && ny >= 2) || (nr + ny == 5))
	{
		cout << "nakhor lite";
	}
	else
	{
		cout << "rahat baash";
	}
	return 0;
}