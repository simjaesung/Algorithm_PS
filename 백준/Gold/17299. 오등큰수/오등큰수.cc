#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin >> n;

	vector<int> A(n);
	vector<int> Count(1000001);
	vector<int> F(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
		Count[A[i]]++;
	}

	stack<int> stack;
	stack.push(0);

	for (int i = 1; i < n; i++) {
		while( !stack.empty() && 
			Count[A[stack.top()]] < Count[A[i]]){
			F[stack.top()] = A[i];
			stack.pop();
		}
		stack.push(i);
	}

	while (!stack.empty()) {
		F[stack.top()] = -1;
		stack.pop();
	}

	for (auto x : F)
		cout << x << ' ';
	
	return 0;
}