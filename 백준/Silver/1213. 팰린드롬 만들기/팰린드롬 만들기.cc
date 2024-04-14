#include<iostream>
using namespace std;
int arr[26];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s,ans;
    string m = ""; //중간 값
    
    cin >> s;
    for(auto x : s) arr[x -'A']++;
    
    for(int i = 0; i<26; i++){
        if(arr[i] % 2 == 1) {
            if(m.length() > 0){
                //홀수인 개수가 2개이상 나오면 팰린들롬 불가
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            else {
                //중간 값 설정
                m = 'A' + i;
                arr[i]--;
            }
        }
        if(arr[i] < 2) continue;
        int tmp = arr[i] / 2;
        while(tmp--){
            ans += 'A' + i;
        }
        arr[i] /= 2;
    }
    
    ans += m;
    
    for(int i = 25; i>=0; i--){
        int tmp = arr[i];
        while(tmp--){
            ans += 'A' + i;
        }
    }
    cout << ans;
    return 0;
}