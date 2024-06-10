#include <iostream>
using namespace std;
string s;
char duck[5] = {'q','u','a','c','k'};
int check[30];
int ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s;
    for(int i = 0; i<s.length(); i++) check[s[i]-'a']++;
    
	while(1){
		int check = 1; //다른 오리의 소리가 더들렸는지 체크
		int idx = 0; //duck의 
		string tmp;  //quack저장 문자열
		for(int i = 0; i<s.length(); i++){
			if(s[i] == duck[idx]){
				tmp += s[i];
				s[i] = '.';
				idx++;
			}
			if(tmp == "quack") {
                tmp = "";
                idx = 0;
            }
            if(s[i] != '.') check = 0;
		}
        for(int i = 0; i<s.length(); i++){
            if(s[i] != '.' && s[i] != 'q'){
                cout << -1;
                return 0;
            }
            if(s[i] == 'q') break;
        }
		if(tmp.length() > 0){
			cout << -1;
			return 0;
		}
        ans++;
        if(check) break; //더이상 오리가 없음
	}
	cout << ans;
	return 0;
}