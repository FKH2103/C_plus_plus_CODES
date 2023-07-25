#include <iostream>
using namespace std;
int main() 
{
	int n,j=0,k=0,q=0;
	cin >> n;
	int mimo[40];
	int memo[40];
	int temp[40];
	int num[40];
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		int x = i % 2;
		int y= num[i] % 2;
		if (x == y)
		{
			temp[j]= num[i];
			++j;
		}
		else
		{
			if ((x ==0) && (y==1))
			{
				memo[k] = num[i];
			    ++k;
			}
			if ((x == 1) && (y == 0))
			{
				mimo[q] = num[i];
				++q;
			}
			
		}
	}
	if (q != k) 
	{
		int z = -1;
		cout << z ;

	}
	if (q == k)
	{
		
		cout << q;

	}

	
	return 0;
}
