#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,lena,lenb;
string a,b;
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    while(n--){
        cin >> a >> b;
        lena = a.length(); lenb = b.length();
        int cA[26] = {0,};
        int cB[26] = {0,};
        if(lena != lenb) {
            cout << a << " & " << b <<" are NOT anagrams.\n";
            continue;
        }
        for(int i = 0; i<lena; i++){
            cA[a[i]-'a']++;
            cB[b[i]-'a']++;
        }
        
        int check = 1;
        
        for(int i = 0; i<26; i++){
            if(cA[i] != cB[i]) {
                check = 0; break;
            }
        }
        if(check) cout << a << " & " << b <<" are anagrams.\n";
        else cout << a << " & " << b <<" are NOT anagrams.\n";
    }
    return 0;
}