#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> before;
unordered_map<string, int> after;
string t1, t2, t3, c1, c2;
int ans;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t1 >> t2 >> t3;

    while (1) {
        cin >> c1 >> c2;
        if (cin.eof()) break;
        if (c1 <= t1) {
            if (before.find(c2) == before.end())
                before[c2] = 1;
        }

        if (c1 >= t2 && c1 <= t3)
            if (after.find(c2) == after.end())
                after[c2] = 1;
    }


    for (auto x : before) {
        if (after.find(x.first) != after.end()) ans++;
    }

    cout << ans;

    return 0;

}