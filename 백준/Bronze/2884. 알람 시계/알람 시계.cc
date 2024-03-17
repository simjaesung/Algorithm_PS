#include <iostream>
using namespace std;

int main() {
	int hour, min;
	cin >> hour >> min;
	if (min < 45) {
		min = 60 - (45 - min);
		hour -= 1;
	}
	else {
		min -= 45;
	}

	if (hour < 0) {
		hour = 24 + hour;
	}

	cout << hour << " " << min;


	return 0;

}