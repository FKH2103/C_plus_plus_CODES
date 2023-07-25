#include <iostream>
using namespace std;
int main()
{
	int n, q;
	cin >> n;
	char s[50][11];
	for (int i = 0; i < 50; )
	{
		cin >> s[i];
		++i;
		if (i >= n)
		{
			break;
		}
	}


	for (int i = 0; i < 50; )
	{

		q = i - 1;
		for (int r = 0; q >= 0;)
		{
			if (i == 0)
			{
				break;
			}
			cout << s[i] << ": salam " << s[q] << "!" << endl;
			--q;
			++r;

		}

		++i;
		if (i >= n)
		{
			break;
		}

	}




	for (int i = 0; i < 50; )
	{
		cout << s[i] << ": khodafez bacheha!" << endl;
		++i;
		if (i >= n)
		{
			break;
		}
		--i;

		q = i + 1;
		for (int r = 0; ;)
		{

			cout << s[q] << ": khodafez " << s[i] << "!" << endl;
			++q;
			++r;
			if (q >= n)
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




	return 0;
}