#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
int tedadhalat(int s)
{
	int a, b, c, d, i = 0;
	for (a = 1; a <= 3; a++)
		for (b = 1; b <= 3; b++)
			for (c = 1; c <= 3; c++)
				for (d = 1; d <= 3; d++)
					if (s == a + b + c + d)
						++i;

	return i;
}
int herasat(int a, char A[3])
{
	if (A[0] == '0' && a != 1)
		return 0;
	int sum = 0;
	for (int i = 0; i < a; ++i)
	{
		sum += int(A[i]) * pow(100, (a - 1 - i));
	}
	if (sum > 505353)
		return 0;

	return 1;
}
int main()
{
	char A[3], B[3], C[3], D[3];
	int a, b, c, d;
	char s[20];
	cin >> s;

	int tool = strlen(s);
	if (tool < 4 && tool > 12)
		return 0;
	if (tool >= 4 && tool <= 12)
	{
		for (a = 1; a <= 3; a++)
			for (b = 1; b <= 3; b++)
				for (c = 1; c <= 3; c++)
					for (d = 1; d <= 3; d++)
						if (tool == a + b + c + d)
						{

							for (int j = 0; j < a; ++j)
								A[j] = s[j];
							for (int j = 0; j < b; ++j)
								B[j] = s[j + a];
							for (int j = 0; j < c; ++j)
								C[j] = s[j + a + b];
							for (int j = 0; j < d; ++j)
								D[j] = s[j + a + b + c];

							int aa = herasat(a, A);
							int bb = herasat(b, B);
							int cc = herasat(c, C);
							int dd = herasat(d, D);


							if (aa == 1 && bb == 1 && cc == 1 && dd == 1)
							{
								for (int j = 0; j < a; ++j)
									cout << A[j];
								cout << '.';
								for (int j = 0; j < b; ++j)
									cout << B[j];
								cout << '.';
								for (int j = 0; j < c; ++j)
									cout << C[j];
								cout << '.';
								for (int j = 0; j < d; ++j)
									cout << D[j];
								cout << endl;
							}
						}
	}
	return 0;
}