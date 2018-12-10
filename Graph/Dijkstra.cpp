typedef struct Edge {
    int v; LL w;
    bool operator > (const Edge &b) const {
        return w > b.w;
    }
} State;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
void Dijkstra(int n, vector<vector<Edge> > &G, vector<LL> &d, int s, int t = -1) {
    static priority_queue<State, vector<State>, greater<State> > pq;
    d.clear(); d.resize(n);
    while (pq.size()) pq.pop();
    for (auto &num : d) num = INF;
    d[s] = 0; pq.push({s, d[s]});
    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        int u = p.v;
        if (d[u] < p.w) continue;
        if (u == t) return ;
        for (auto &e : G[u]) {
            if (d[e.v] > d[u] + e.w) {
                d[e.v] = d[u] + e.w;
                pq.push({e.v, d[e.v]});
            }
        }
    }
}
