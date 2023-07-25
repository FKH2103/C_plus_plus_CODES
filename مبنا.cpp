#include <iostream>
using namespace std;
int mabna(int a, int b, int c[17])
{
	int i = 0;
	int w, q;
	w = a / b;
	while (w != 0)
	{
		w = a / b;
		q = a % b;
		a = w;
		c[i] = q;
		++i;
	}
	return i;
}
int  main()
{
	int c[17];
	int a, b, n;
	cin >> a >> b;
	n = mabna(a, b, c);
	

	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < n; i = i + 2)
		sum1 += c[i];
	for (int i = 1; i < n; i = i + 2)
		sum2 += c[i];
	if (sum1 == sum2)
		cout << "Yes";
	else if (sum1 != sum2)
		cout << "No";
	return 0;

}