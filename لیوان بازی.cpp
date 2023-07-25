#include <iostream>
using namespace std;
int main()
{
	int i, j, n;
	char x;
	cin >> n >> x;
	char a[1000][2];
	for (i = 0; i < n; i++)
	{
		cin >> a[i][0];
		cin >> a[i][1];

	}



	char b = x;
	for (i = 0; i < n; ++i)
	{
		if (a[i][0] == b)
		{
			b = a[i][1];
		}
		else
		{
			if (a[i][1] == b)
			{
				b = a[i][0];
			}
		}

	}
	cout << b;





	return 0;
}
