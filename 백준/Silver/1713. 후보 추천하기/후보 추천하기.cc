//비어있음
//추천하면 게시하는데, 꽉차있으면 제일 투표적은애꺼 삭제 후 새로운 사람 기재
//투표가 적은 사람이 2명 이상이면 오래된거 삭제, 삭제되면 추천받은 횟수 0
//본인 투표 불가
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,k; 
int a,b,c;
//사진개수, 추천횟수
int pic[105]; //등록된 학생 저장
vector<tuple<int,int,int>>v; //투표수,투표 순서,학생번호
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    int cur = 0; //현재 걸린 사진 개수
    for(int i = 0; i<k; i++){
        sort(v.begin(),v.end());
        
        int vote; cin >> vote;
        
        if(pic[vote]){
            for(int i = 0; i<v.size(); i++){
                tie(a,b,c) = v[i];
                if(c == vote) {
                    a++;
                    v[i] = {a+1,b,c};
                    break;
                }
            }
        }
        else if(v.size() < n){
            v.push_back({1,i,vote});
            pic[vote] = 1;
        }
        else{
            tie(a,b,c) = v[0];
            pic[c] = 0;
            v.erase(v.begin());
            v.push_back({1,i,vote});
            pic[vote] = 1;
        }
    }
    
    for(int i = 1; i<=100; i++) if(pic[i]) cout << i << ' ';
    return 0;
}

