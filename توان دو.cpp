#include <iostream>
using namespace std;
int main() {
	int n,x;
	cin >> n;
	x = 1;
	do 
	{
		x = x* 2;
	}while (x <= n);
	cout << x;
	return 0;
}

