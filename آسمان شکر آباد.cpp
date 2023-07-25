#include <iostream>
using namespace std;
int main()
{
	int n, m, r = 0;
	cin >> n >> m;
	char a[100][100];

	for (int i = 0; i < 100; )
	{
		for (int j = 0; j < 100; )
		{
			cin >> a[i][j];

			++j;

			if (j >= m)
			{
				break;

			}


		}
		++i;
		if (i >= n)
		{
			break;

		}
	}
	
	char x = '*';
	for (int i = 0; i < 100; )
	{
		for (int j = 0; j < 100; )
		{
			if (a[i][j] == x) 
			{
				++r;

			}
			
			++j;

			if (j >= m)
			{
				break;

			}


		}
		++i;
		if (i >= n)
		{
			break;

		}
	}
	cout << r;

 return 0;
}