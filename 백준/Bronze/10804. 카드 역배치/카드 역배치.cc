#include<iostream>
using namespace std;
int main()
{
	int card[21];
	for (int i = 1; i <= 20; i++) card[i] = i;

	int a,b,n = 10;

	while (n--) {
		cin >> a >> b;
		for (int i = 0; i <= (b - a) / 2; i++) swap(card[a + i], card[b - i]);
	}
	for (int i = 1; i <= 20; i++) cout << card[i] << ' ';
	
	return 0;
}