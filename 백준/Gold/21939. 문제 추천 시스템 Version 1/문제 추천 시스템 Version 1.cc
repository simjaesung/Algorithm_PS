#include<iostream>
#include<set>
using namespace std;
int arr[100005];
int n,m,num,s;
string cmd;
multiset<pair<int,int>>m_set;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> num >> s;
        arr[num] = s;
        m_set.insert(make_pair(s,num));
    }
    
    cin >> m;
    for(int i = 0; i<m; i++){
        cin >> cmd;
        if(cmd == "add"){
            cin >> num >> s;
            arr[num] = s;
            m_set.insert(make_pair(s,num));
        }
        else if (cmd == "solved"){
            cin >> num;
            auto idx = m_set.find(make_pair(arr[num],num));
            m_set.erase(idx);
        }
        else if (cmd == "recommend"){
            cin >> num;
            if(num == 1) cout << prev(m_set.end()) -> second << '\n';
            else cout << m_set.begin() -> second << '\n';
        }
    }
    
    return 0;
}