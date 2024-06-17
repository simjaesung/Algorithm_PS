#include<iostream>
#include<vector>
using namespace std;
int r,c,t; //가로 세로 상점개수
int dw,dl,w,l; //동근의 위치와, 상점의 위치
int ans;
vector<pair<int,int>>v; //상점 넣을 곳
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c >> t; //가로,세로,상점
    
    for(int i = 0; i<t; i++){
         //위치와 떨어진 거리
        cin >> w >> l;
        v.push_back({w,l});
    }
    
    cin >> dw >> dl; //동근의 위치
    
    for(int i = 0; i<t; i++){
        w = v[i].first; l = v[i].second;
        //1:북,2:남,3:서,4:동
        if(dw + w == 3){ //북남
            ans += c;
            ans += min(dl + l, r-dl + r-l);
        }
        else if(dw + w == 7){ //서동
            ans += r;
            ans += min(dl + l, c-dl + c-l);
        }
        else if(dw == w){ //같은 선상
            ans += abs(dl-l);
        }
        else{ //수직
            if(dw == 1 || dw == 3){
                if(w == 3 || w == 1){ //북서
                    ans += dl + l;
                }
                else if(w == 4 || w == 2){ //북동
                    ans += r-dl + l;
                }
            }
            else if(dw == 2 || dw == 4){
                if(w == 3 || w == 1){ //남서
                    ans += dl + c-l;
                }
                else if(w == 4 || w == 2){ //남동
                    ans += r-dl + c-l;
                }
            }
        }
    }
    
    cout << ans;
    
    return 0;
}