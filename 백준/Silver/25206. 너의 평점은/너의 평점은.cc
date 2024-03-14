#include<iostream>
using namespace std;
string sub, grade;
double s, tmp, sum, p;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 20; i++) {
		cin >> sub >> s >> grade;
		if (grade == "A+") tmp = 4.5;
		else if (grade == "A0") tmp = 4.0;
		else if (grade == "B+") tmp = 3.5;
		else if (grade == "B0") tmp = 3.0;
		else if (grade == "C+") tmp = 2.5;
		else if (grade == "C0") tmp = 2.0;
		else if (grade == "D+") tmp = 1.5;
		else if (grade == "D0") tmp = 1.0;
		else if (grade == "F") tmp = 0.0;
		else continue;
			
		p += s;
		sum += tmp * s; 
	}
	cout << fixed;
	cout.precision(6);
	cout << sum / p;
	return 0;
}