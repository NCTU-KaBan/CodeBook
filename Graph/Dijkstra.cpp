#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int INF = 0x3f3f3f3f;
vector<double> Dijkstra(vector<vector<pair<int, double> > > &G, int s, int t) {
    vector<double> d(G.size(), INF);
    vector<bool> done(G.size(), false);
    priority_queue<pair<double, int> > pq;
    d[s] = 0; pq.push({-d[s], s});
    while (pq.size()) {
        pair<double, int> p = pq.top(); pq.pop();
        int u = p.second; done[u] = true;
        for (auto e : G[u]) {
            if (d[e.first] < d[u] + e.second) continue;
            d[e.first] = d[u] + e.second;
            if (!done[e.first])
                pq.push({-d[e.first], e.first});
        }
    }
    return d;
}
double dist(pair<double, double> &p_1, pair<double, double> &p_2) {
    double res = 0;
    res += (p_1.F - p_2.F) * (p_1.F - p_2.F);
    res += (p_1.S - p_2.S) * (p_1.S - p_2.S);
    return sqrt(res);
}
int main() {
    int kase = 0;
    int n; while (cin >> n && n) {
        cout << "Scenario #" << ++kase << '\n';
        cout << "Frog Distance = ";
        vector<pair<double, double> > data(n);
        for (auto &p : data)
            cin >> p.F >> p.S;
        vector<vector<pair<int, double> > > G(n);
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (i == j) continue;
                G[i].push_back({j, dist(data[i], data[j])});
                G[j].push_back({i, dist(data[i], data[j])});
            }
        }
        vector<double> d = Dijkstra(G, 0, 1);
        cout << fixed << setprecision(3) << d[1] << '\n';
        cout << '\n';
    }
}
