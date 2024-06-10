#include<iostream>
using namespace std;
int n,m,val;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while(n--){
        int ma = -1000001;
        int mi = 1000001;
        cin >> m;
        for(int i = 0; i<m; i++) {
            cin >> val;
            ma = max(val,ma);
            mi = min(val,mi);
        }
        cout << mi << ' '<< ma << '\n';
    }
    return 0;
}