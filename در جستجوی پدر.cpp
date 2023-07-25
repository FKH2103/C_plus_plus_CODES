#include <iostream>
using namespace std;
int jamragham(int n)
{
	int N = n;
	int a, sum = 0;
	while (N > 0)
	{
		a = N % 10;
		sum += a;
		N = N / 10;
	}
	return sum;
}
int sumofprimeFactors(int n)
{
	int sum = 0;
	for (int i = 2; i <= n; i = i + 1)
	{

		if (n % i == 0)

		{
			while (n % i == 0)
			{

				n = n / i;
			}

			sum = sum + i;
		}

	}

	return sum;
}
int main()
{
	int d;
	int t;
	cin >> t;
	int a[100];
	for (int i = 0; i < t; i++)
	{
		cin >> d;
		a[i] = d;
	}
	for (int i = 0; i < t; i++)
	{
		int d, Flag = 0;
		d = a[i];

		for (int n = 4; n < d; ++n)
		{

			int sum = jamragham(n);
			int saval = sumofprimeFactors(n);
			int D = n + sum + saval;

			if (d == D)
			{
				Flag = 1;
				break;
			}
			else if (d != D)
				Flag = 0;
		}

		if (Flag == 0)
			cout << "No";
		if (Flag == 1)
			cout << "Yes";
		cout << endl;
	}
	return 0;
}