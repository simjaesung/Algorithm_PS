#include<iostream>
#include<algorithm>
using namespace std;
int n,l,h;
int a[1005];
int main()
{
	cin >> n >> l;
    for(int i = 0; i<n; i++) cin >> a[i];
    sort(a,a+n);
    
    for(int i = 0; i<n; i++) if(a[i] <= l) l++;
    cout << l;

	return 0;
}