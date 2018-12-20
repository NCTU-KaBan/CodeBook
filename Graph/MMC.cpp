const int MAXN = 55;
const double INF = 0x3f3f3f3f;
const double EPS = 1e-4;
double min_mean_cycle(vector<vector<pii> > &G) {
    int n = G.size(); G.resize(n + 1);
    for (int i = 0 ; i < n ; i++)
        G[n].push_back(MP(i, 0));
    double d[MAXN][MAXN];   // dp[i][j] := 從起點到j走i條的最短路徑
    int s = n++;
    for (int i = 0 ; i <= n ; i++)
        for (int j = 0 ; j < n ; j++)
            d[i][j] = INF;
    d[0][s] = 0;
    for (int k = 0 ; k < n ; k++)
        for (int i = 0 ; i < n ; i++)
            for (auto p : G[i])
                if (d[k][i] + p.S < d[k + 1][p.F])
                    d[k + 1][p.F] = d[k][i] + p.S;

    double ans = INF;
    for (int i = 0 ; i < n ; i++) {
        if (fabs(d[n][i] - INF) < EPS) continue;
        double maxW = -INF;
        for (int k = 0 ; k < n - 1 ; k++) {
            maxW = max(maxW, (d[n][i] - d[k][i]) / (n - k));
        }
        ans = min(ans, maxW);
    }
    return ans;
}
int main() {
    int kase = 0;
    int t; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": ";
        int n, m; cin >> n >> m;
        vector<vector<pii > > G(n);
        while (m--) {
            int a, b, c; 
            cin >> a >> b >> c;
            a--, b--;
            G[a].push_back(MP(b, c));
        }
        double ans = min_mean_cycle(G);
        if (fabs(ans - INF) < EPS) cout << "No cycle found.\n";
        else printf("%f\n", ans + EPS);
    }
}
