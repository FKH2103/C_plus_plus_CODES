#include <iostream>
using namespace std;
int main() {
	int n,x;
	char y;
	cin >> n;
	cin >> y;
	x = n % 2;
	if (x == 1) {
		cout << "ranandegi";
		if (y == 97 || y==100 || y==101) {
			cout << "ba chatr";
		}
		if (y == 99 || y == 98 ) {
			cout << "bi chatr";
		}
		
	}
	if (x == 0) {
		cout << "bashgah";
		if (y == 97 || y == 100 || y == 101) {
			cout << "ba chatr";
		}
		if (y == 99 || y == 98) {
			cout << "bi chatr";
		}

	}
	
	return 0;
}
