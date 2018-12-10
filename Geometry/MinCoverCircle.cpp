#include <bits/stdc++.h>
using namespace std;

typedef double T;
#define EPS 1e-12

class POS {
    public:
        T x, y;
        POS(const T& x = 0, const T & y = 0) : x(x), y(y) {}
        // operator + - /
};


T dot(POS p, POS q)   {}
T dist2(POS p, POS q) {}
double dist(POS p, POS q)  {}

POS ComputeCircleCenter(POS a, POS b, POS c) {}

pair<POS, T> MinCoverCircle(vector<POS> points) {
    T r = 0; int pn = points.size();
    if (pn == 0) {
        return pair<POS, T>(POS(0, 0), 0);
    }
    POS ret = points[0]; 
    for (int i = 1; i < pn; i ++) {
        if (dist(points[i], ret) > r + EPS) {
            ret = points[i]; r = 0;
            for (int j = 0; j < i; j ++) {
                if (dist(points[j], ret) > r + EPS) {
                    ret.x = (points[i].x + points[j].x) / 2;
                    ret.y = (points[i].y + points[j].y) / 2;
                    r = dist(points[j], ret);
                    for (int k = 0; k < j; k ++) {
                        if (dist(points[k], ret) > r + EPS) {
                            ret = ComputeCircleCenter(points[i], points[j], points[k]);
                            r = dist(points[i], ret);
                        }
                    }
                }
            }
        }
    }
    return pair<POS, T>(ret, r); // center, radius
}

int main() {
    int n;
    while (cin >> n && n) {
        vector<POS> points(n);
        for (int i = 0; i < n; i ++) 
            cin >> points[i].x >> points[i].y;
        pair<POS, double> ans = MinCoverCircle(points);
    }    
}
