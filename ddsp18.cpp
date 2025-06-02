#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;

class Solution {
    int R,C,E;
    vector<string> G;
    vector<pair<int,int>> P;
    vector<vector<int>> D;
    const int M = 1e9+7;
    int di[4] = {-1,1,0,0}, dj[4] = {0,0,-1,1};

    void bfs(int x) {
        int n = P.size();
        D[x] = vector<int>(n, M);
        vector<vector<vector<bool>>> vis(R, vector<vector<bool>>(C, vector<bool>(E+1, false)));
        queue<tuple<int,int,int,int>> q;
        auto [a,b] = P[x];
        vis[a][b][E] = true;
        q.emplace(a,b,E,0);
        while (!q.empty()) {
            auto [i,j,en,st] = q.front(); q.pop();
            for (int t = 0; t < n; t++)
                if (t != x && P[t].first == i && P[t].second == j && D[x][t] == M)
                    D[x][t] = st;
            if (en == 0) continue;
            for (int z = 0; z < 4; z++) {
                int ni = i + di[z], nj = j + dj[z];
                if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
                char cc = G[ni][nj];
                if (cc == 'X') continue;
                int ne = en - 1;
                if (cc == 'R') ne = E;
                if (!vis[ni][nj][ne]) {
                    vis[ni][nj][ne] = true;
                    q.emplace(ni, nj, ne, st + 1);
                }
            }
        }
    }

public:
    int minMoves(vector<string>& cl, int en) {
        G = cl;
        R = G.size();
        C = G[0].size();
        E = en;
        P.clear();
        pair<int,int> s;
        vector<pair<int,int>> L;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                if (G[i][j] == 'S') s = {i, j};
                else if (G[i][j] == 'L') L.emplace_back(i, j);
            }
        P.push_back(s);
        for (auto& x : L) P.push_back(x);
        int n = P.size();
        if (n == 1) return 0;
        D.assign(n, vector<int>(n, M));
        for (int i = 0; i < n; i++) bfs(i);

        queue<int> qp;
        queue<vector<bool>> qb;
        queue<int> qs;
        map<pair<int, vector<bool>>, int> dist;
        vector<bool> cb(L.size(), false);
        qp.push(0);
        qb.push(cb);
        qs.push(0);
        dist[{0, cb}] = 0;

        while (!qp.empty()) {
            int u = qp.front(); qp.pop();
            vector<bool> cur = qb.front(); qb.pop();
            int st = qs.front(); qs.pop();
            bool all = true;
            for (bool x : cur) if (!x) all = false;
            if (all) return st;
            for (int nx = 1; nx < n; nx++) {
                if (D[u][nx] == M) continue;
                if (cur[nx - 1]) continue;
                vector<bool> nc = cur;
                nc[nx - 1] = true;
                int nd = st + D[u][nx];
                auto key = make_pair(nx, nc);
                if (!dist.count(key) || dist[key] > nd) {
                    dist[key] = nd;
                    qp.push(nx);
                    qb.push(nc);
                    qs.push(nd);
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<string> cl1 = {"L.S", "RXL"};
    int e1 = 3;
    Solution sol;
    cout << sol.minMoves(cl1, e1) << "\n"; // -1

    vector<string> cl2 = {"S.", "XL"};
    int e2 = 2;
    cout << sol.minMoves(cl2, e2) << "\n"; // 2
    return 0;
}
