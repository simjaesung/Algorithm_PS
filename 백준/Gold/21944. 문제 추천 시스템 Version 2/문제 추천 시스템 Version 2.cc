#include<iostream>
#include<set>
using namespace std;

multiset<pair<int, int>> ms_seper[105];
multiset<pair<int, int>> ms_all;

int n, m, p, l, g;
pair<int, int> arr[100005];
//문제 번호의 난이도와 분류
string cmd;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        //문제 번호, 난이도, 분류
        cin >> p >> l >> g;
        arr[p] = { l,g };
        ms_all.insert({ l,p });
        ms_seper[g].insert({ l,p });
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> cmd;
        int P, L, G, x;
        if (cmd == "recommend") {
            cin >> G >> x;
            if (x == 1) cout << prev(ms_seper[G].end())->second << '\n';
            else cout << ms_seper[G].begin()->second << '\n';
        }
        else if (cmd == "recommend2") {
            cin >> x;
            if (x == 1) cout << prev(ms_all.end())->second << '\n';
            else cout << ms_all.begin()->second << '\n';
        }
        else if (cmd == "recommend3") {
            cin >> x >> L;
            if (x == 1) {
                auto iter = ms_all.lower_bound({ L,1 });
                if (iter != ms_all.end()) cout << iter->second << '\n';
                else cout << -1 << '\n';
            }
            else {
                auto iter = ms_all.lower_bound({ L,1 });
                if (iter != ms_all.begin())
                    cout << prev(iter)->second << '\n';
                else cout << -1 << '\n';
            }
        }
        else if (cmd == "add") {
            cin >> P >> L >> G;
            arr[P] = { L,G };
            ms_seper[G].insert({ L,P });
            ms_all.insert({ L,P });
        }
        else if (cmd == "solved") {
            cin >> P;
            auto idx1 = ms_all.find({ arr[P].first, P });
            auto idx2 = ms_seper[arr[P].second].find({ arr[P].first, P });
            ms_all.erase(idx1);
            ms_seper[arr[P].second].erase(idx2);
        }
    }
    return 0;
}