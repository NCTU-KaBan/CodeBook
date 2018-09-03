#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct Point {
    int x, y;
    Point operator - (const Point &rhs) const {
        Point ret;
        ret.x = x - rhs.x;
        ret.y = y - rhs.y;
        return ret;
    }
} P[MAXN];
int n;
typedef Point Vector;
int cross(Vector v1, Vector v2) {
    return v1.x * v2.y - v1.y * v2.x;
}
int cross(Point o, Point a, Point b) {
    return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x);
}
Point L[MAXN+1], U[MAXN];
bool cmp(Point a, Point b) {
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}
int rotating_caliper() {
    sort(P, P+n, cmp);
    int l = 0, u = 0;
    for (int i = 0 ; i < n ; i++)
    {
        while (l >= 2 && cross(L[l-2], L[l-1], P[i]) <= 0) l--;
        while (u >= 2 && cross(U[u-2], U[u-1], P[i]) >= 0) u--;
        L[l++] = P[i];
        U[u++] = P[i];
    }
    if (u-2 >= 0) L[l] = U[u-2];
    int max_dist = 0;
    for (int i = 0, j = u-1 ; i < l && j > 0 ; )
    {
        max_dist = max(max_dist, (L[i].x - U[j].x) * (L[i].x - U[j].x) + (L[i].y - U[j].y) * (L[i].y - U[j].y));
        if (cross(L[i+1] - L[i], U[j-1] - U[j]) < 0)
            i++;
        else
            j--;
    }
    return max_dist;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        cin >> n; for (int i = 0 ; i < n ; i++) {
            cin >> P[i].x >> P[i].y;
        }
        cout << rotating_caliper() << '\n';
    }
}

