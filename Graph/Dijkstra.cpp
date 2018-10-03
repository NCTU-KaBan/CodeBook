#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
vector<int> Dijkstra(vector<vector<pii> > &G, int s, int t) {
    vector<int> d(G.size(), INF);
    priority_queue<pii> pq;
    d[s] = 0; pq.push({-d[s], s});
    while (pq.size()) {
        pii p = pq.top(); pq.pop();
        int u = p.second;
        if (d[u] < -p.first) continue;
        for (auto e : G[u]) {
            if (d[e.first] < d[u] + e.second) continue;
            d[e.first] = d[u] + e.second;
            pq.push({-d[e.first], e.first});
        }
    }
    return d;
}
int main() {
    int n, m; cin >> n >> m;
    vector<vector<pii> > G(n);
    for (int i = 0 ; i < m ; i++) {
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    vector<int> d = Dijkstra(G, 0, n - 1);
    for (int i = 0 ; i < n ; i++)
        cout << d[i] << ' ';
    cout << '\n';
}
