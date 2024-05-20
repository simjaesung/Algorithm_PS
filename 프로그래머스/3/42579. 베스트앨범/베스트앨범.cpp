#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<string,int>a, pair<string,int>b){
    return a.second > b.second;
}

bool cmp2(pair<int,int>a, pair<int,int>b){
    if(a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string,int>um;
    vector<pair<string,int>>tmp;
    string s1,s2;
    
    vector<int> answer;
    
    int len = plays.size();
    for(int i = 0; i<len; i++) um[genres[i]] += plays[i];
    
    for(auto x : um) tmp.push_back({x.first, x.second});
    sort(tmp.begin(),tmp.end(),cmp);
    
    for(auto x : tmp){
        vector<pair<int,int>>g; //most 1장르
        for(int i = 0; i<len; i++){
            if(genres[i] == x.first) g.push_back({plays[i],i});
        }
        int cnt = 0;
        sort(g.begin(),g.end(),cmp2);
        for(auto x : g){
            answer.push_back(x.second);
            cnt++;
            if(cnt == 2) break;
        }
    }
    
    return answer;
}