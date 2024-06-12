#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string,vector<int>>m;
    
    for(auto s : info){
        vector<string>v[4];
        int idx = 0;
        string tmp;
        for(int i = 0; i<s.length(); i++){
            if(s[i] != ' ') tmp += s[i];
            else{
                v[idx].push_back(tmp);
                v[idx].push_back("-");
                tmp = "";
                idx++;
            }
        }
        
        int score = stoi(tmp);
        for(int i = 0; i<2; i++){
            string k1,k2,k3,k4;
            k1 = v[0][i];
            for(int j = 0; j<2; j++) {
                k2 = v[1][j];
                for(int l = 0; l<2; l++) {
                    k3 = v[2][l];
                    for(int h = 0; h<2; h++) {
                        k4 = v[3][h];
                        m[k1+k2+k3+k4].push_back(score);
                    }
                }
            }
        }
    }
    
    for(auto itr = m.begin(); itr != m.end(); itr++){
        sort(itr->second.begin(), itr->second.end());
    }

    for(auto s : query){
        string key;
        string tmp;
        for(int i = 0; i<s.length(); i++){
            if(s[i] != ' ') tmp += s[i];
            else{
                if(tmp.compare("and")) key += tmp;
                tmp = "";
            }
        }
        int anstmp = lower_bound(m[key].begin(),m[key].end(),stoi(tmp)) - (m[key].begin());
        answer.push_back(m[key].size() - anstmp);
    }
    return answer;
}