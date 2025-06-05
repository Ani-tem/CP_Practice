#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<long long> v(m);
        for (int i = 0; i < m; i++) {
            cin >> v[i];
        }

        priority_queue<pair<long long, long long>> mx;
        for (long long x : v) {
            long long y = x / 100;
            mx.push({y, x});
            if (mx.size() > (size_t)n) {
                mx.pop();
            }
        }

        vector<long long> s;
        while (!mx.empty()) {
            s.push_back(mx.top().second);
            mx.pop();
        }

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> mn;
        for (long long x : v) {
            long long y = x / 100;
            mn.push({y, x});
            if (mn.size() > (size_t)n) {
                mn.pop();
            }
        }

        vector<long long> tup;
        while (!mn.empty()) {
            tup.push_back(mn.top().second);
            mn.pop();
        }

        for (int i = 0; i < n; i++) {
            cout << s[i] << ' ' << tup[i] << ' ' << s[i] << ' ' << tup[i] << ' ' << s[i] << ' ' << tup[i] <<endl;
        }
    }
}
