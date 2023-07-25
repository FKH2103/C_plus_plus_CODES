#include <iostream>
using namespace std;

int main()
{


	int r = 0, t = 0;
	int a[100] = { 0 };
	int SUM = 0;
	for (r = 0; r < 100; )
	{
		cin >> a[r];



		if (a[r] == (-1))
		{
			a[r] == 0;
			break;
		}


		int z = a[r];
		do
		{
			t = (t * 10) + (z % 10);
			z = z / 10;

		} while (z >= 1);

		SUM = SUM + (2 * t);
		t = 0;

		++r;


	}


	cout << SUM;
	return 0;
}