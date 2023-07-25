#include <iostream>

using namespace std;

int main() {
	int x, y;
	cin >> x;
	cin >> y;


	if (x < 150) {
		if (y < 40)
			cout << "laghar";
		if (y >= 40 && y <= 50)
			cout << "normal";
		if (y > 50)
			cout << "chagh";
	}
	if (x >= 150 && x <= 180) {
		if (y < 50)
			cout << "laghar";
		if (y >= 50 && y <= 80)
			cout << "normal";
		if (y > 80)
			cout << "chagh";

	}
	if (x > 180) {
		if (y < 80)
			cout << "laghar";
		if (y >= 80 && y <= 90  )
			cout << "normal";
		if (y > 90)
			cout << "chagh";

	}



	return 0;
}