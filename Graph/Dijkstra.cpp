#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Edge {
    int v; LL w;
    bool operator < (const Edge &e) const {
        return w > e.w;
    }
};
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
vector<LL> Dijkstra(vector<vector<Edge> > &G, int s) {
    vector<LL> d(G.size(), INF);
    priority_queue<Edge> pq;
    d[s] = 0; pq.push({s, d[s]});
    while (pq.size()) {
        Edge p = pq.top(); pq.pop();
        if (d[p.v] < p.w) continue;
        for (auto e : G[p.v]) {
            if (d[e.v] < d[p.v] + e.w) continue;
            d[e.v] = d[p.v] + e.w;
            pq.push({e.v, d[e.v]});
        }
    }
    return d;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; while (cin >> n >> m) {
        vector<vector<Edge> > G(n);
        while (m--) {
            int u, v; LL w; cin >> u >> v >> w;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        int s, t; cin >> s >> t;
        vector<LL> d = Dijkstra(G, s);
        cout << (d[t] != INF ? d[t] : -1) << '\n';
    }
}
