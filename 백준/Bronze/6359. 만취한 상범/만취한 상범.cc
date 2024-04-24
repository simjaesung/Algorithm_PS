#include<iostream>
#include<algorithm>
using namespace std;
int room[105];
int t,n;

int main()
{
    cin >> t;
    while(t--){
        int ans = 0;
        fill(room,room + 105,0);
        cin >> n;
        
        for(int i = 1; i<=n; i++){
            int tmp = i;
            while(tmp <= n){
                if(room[tmp]) room[tmp] = 0;
                else room[tmp] = 1;
                tmp += i;
            }
        }
        for(int i = 1; i<=n; i++){
            if(room[i]) ans++;
        }
        cout << ans << '\n';        
    }
}