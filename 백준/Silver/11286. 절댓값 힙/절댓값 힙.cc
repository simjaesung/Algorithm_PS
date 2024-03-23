#include<iostream>
#include<queue>
using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)) return a > b;
        else {
            if(abs(a) < abs(b)) return abs(a) > abs(b);
            else return abs(b) < abs(a);
        }
    }
};

int n,val;
priority_queue<int, vector<int>, cmp> pq;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while(n--){
        cin >> val;
        if(val == 0){
            if(pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';            
                pq.pop();
            }
        }
        else pq.push(val);
    }
    
    return 0;
}