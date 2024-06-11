#include<iostream>
using namespace std;

int arr[20];
int jh_seed, sm_seed, jh_ha, sm_ha;
int seed;

int main()
{
    cin >> seed;
    jh_seed = seed; sm_seed = seed;
    for(int i = 1; i<=14; i++) cin >> arr[i];
    
    //준현
    for(int i = 1; i<=14; i++){
        if(jh_seed == 0) continue;
        if(jh_seed >= arr[i]){
            jh_ha += jh_seed / arr[i];
            jh_seed %= arr[i];
        }
    }
    
    //성민
    int up = 1; int down = 1;
    for(int i = 2; i<=14; i++){
        if(arr[i-1] < arr[i]){
            up ++;
            down = 0;
        }
        else if(arr[i-1] > arr[i]){
            down++;
            up = 0;
        }
        else{
            down = 0;
            up = 0;
        }
        
        if(up >= 3){
            sm_seed += sm_ha * arr[i];
            sm_ha = 0;
        }
        if(down >= 3){
            if(sm_seed == 0) continue;
            sm_ha += sm_seed / arr[i];
            sm_seed %= arr[i];
            
        }
    }
    if(jh_ha * arr[14] + jh_seed > sm_ha * arr[14] + sm_seed) cout << "BNP";
    else if(jh_ha * arr[14] + jh_seed < sm_ha * arr[14] + sm_seed) cout << "TIMING";
    else cout << "SAMESAME";
    //cout << jh_ha * arr[14] + jh_seed<<  ' ' << sm_ha * arr[14] + sm_seed;
    return 0;
}