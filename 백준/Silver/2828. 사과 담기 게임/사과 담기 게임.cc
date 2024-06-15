#include<iostream>
using namespace std;

int n,m,j,ans;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> j;
    int locS = 1; 
    int locE = m;
    
    while(j--){
        int drop;
        cin >> drop;
        if(locE < drop){
            int tmp = drop - locE;
            ans += tmp;
            locS += tmp;
            locE += tmp;
        }
        else if(drop < locS){
            int tmp = locS - drop;
            ans += tmp;
            locS -= tmp;
            locE -= tmp;
        }
    }
    cout << ans;
    return 0;
}