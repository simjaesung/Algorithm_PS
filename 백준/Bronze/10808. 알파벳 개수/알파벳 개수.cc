#include <iostream>
using namespace std;
int arr[26];

int main() {
	string input;
	cin >> input;

	for(char c : input) arr[c - 'a']++;
	for(int k : arr) cout << k << " ";
	
	return 0;
}