#include <iostream>
using namespace std;
int main()
{
	int i, n, d;
	cin >> n >> d;
	if ((n - d)>=0)
	{d = n -d;}
	if ((n - d) < 0)
	{
		d = d-n;
	}


	int c[100] = { 0 };
	for (i = 0; i < n; i++ )
	{
		cin >> c[i];
		
		
	}
	if(d<=n)
	{
	 int temp[100] = { 0 };
	 for (i = 0; i < n; i++ )
	 {
		if ((i - d) < 0)
			temp[i] = c[i + (n - d)];
		if ((i - d) >= 0)
			temp[i] = c[i - d];
		cout << temp[i] ;
		if(i!=(n-1))
		{
			cout << ",";
		}

	 }
	}


	if (d > n)
	{
		d = d - n;
		int temp[100] = { 0 };
		for (i = 0; i < n; i++)
		{
			if ((i - d) < 0)
				temp[i] = c[i + (n - d)];
			if ((i - d) >= 0)
				temp[i] = c[i - d];
			cout << temp[i];
			if (i != (n - 1))
			{
				cout << ",";
			}

		}
	}




	return 0;
}