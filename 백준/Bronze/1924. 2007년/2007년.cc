#include <iostream>
using namespace std;

int main()
{
	
	int MonthDays[] = { 0,31,28,31,30,31,30,31,31,30,31,30 }; //11월 까지
	string Days[] = {"SUN","MON", "TUE", "WED", "THU", "FRI", "SAT"};

	int x, y;
	cin >> x >> y;

	int totalDay = y;

	for (int i = 0; i < x; i++)
		totalDay += MonthDays[i];

	cout << Days[totalDay % 7];

	return 0;
}