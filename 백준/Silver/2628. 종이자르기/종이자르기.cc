#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,m,t;
vector<int>row; // 세로
vector<int>col; // 가로

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> t;
    
    while(t--){
        int a,b;
        cin >> a >> b;
        if(a == 0) col.push_back(b);
        else row.push_back(b);
    }
    row.push_back(0);
    row.push_back(n);
    col.push_back(0);
    col.push_back(m);
    
    sort(row.begin(),row.end());
    sort(col.begin(),col.end());
    
    //현재까지 최대 넓이의 가로세로 시작끝
    int Mrow = 0, Mcol = 0;
    for(int i = 0; i<row.size()-1; i++){
        Mrow = max(row[i+1] - row[i],Mrow);
    }
    
    for(int i = 0; i<col.size()-1; i++){
        Mcol = max(col[i+1] - col[i],Mcol);
    }
    cout << Mrow * Mcol;
    
    return 0;
}