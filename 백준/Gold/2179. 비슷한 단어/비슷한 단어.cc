#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int n,len,same = -1;
string s,a,b,ans1,ans2;
unordered_map<string,int>um;
vector<string>v;

int checklen(string s1, string s2){
    //단어의 길이가 작은 것을 기준으로 비교
    len = min(s1.length(), s2.length());
    int r = 0;
    for(int k = 0; k<len; k++){
        if(s1[k] == s2[k]) r++;
        else break;
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> s; 
        if(!um[s]) um[s] = i; //단어의 인덱스를 해시에 저장
        v.push_back(s);
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            a = v[i]; b = v[j];
            if(um[a] == um[b]) continue; //같은 단어일경우 skip
            
            int tmp = checklen(a,b);
            
            if(tmp == same){
                if(min(um[a],um[b]) < min(um[ans1],um[ans2])){
                    if(um[a] < um[b]){
                        ans1 = a;
                        ans2 = b;
                    }
                    else{
                        ans1 = b;
                        ans2 = a;
                    }
                }
            }
            else if(tmp > same){
                //인덱스가 앞인 것을 S로
                if(um[a] < um[b]){
                    ans1 = a;
                    ans2 = b;
                }
                else{
                    ans1 = b;
                    ans2 = a;
                }
                same = tmp;
            }
            else break;
        }
    }
    cout << ans1 << '\n' << ans2;
    return 0;
}