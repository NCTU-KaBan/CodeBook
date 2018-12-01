#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;

typedef double T;
#define EPS 1e-12

class POS {
	public:
		T x, y;
		POS(const T& x = 0, const T & y = 0) : x(x), y(y) {}
		POS(const POS& x) : x(x.x), y(x.y) {}

		POS& operator+=(const POS& rhs) {
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

		POS const operator-(const POS& rhs) const {
			POS tmp = rhs;
			tmp.x = -tmp.x;
			tmp.y = -tmp.y;
			return POS(*this) += (tmp);
		}

		POS const operator+(const POS& rhs) const {
			return POS(*this) += rhs;
		}	

		POS operator/(T c) const { return POS(x / c, y / c); }
		double operator%(POS rhs) const { return x * rhs.y - y * rhs.x; }
        bool operator<(POS rhs) const { return x < rhs.x || x == rhs.x && y < rhs.y; }
};


T dot(POS p, POS q)   { return p.x * q.x + p.y * q.y; }
T dist2(POS p, POS q) { return dot(p - q, p - q); }
double dist(POS p, POS q)  { return sqrt(dist2(p, q)); }

POS ComputeCircleCenter(POS a, POS b, POS c) {
	POS ret;
	double A1 = b.x - a.x, B1 = b.y - a.y, C1 = (A1 * A1 + B1 * B1) / 2;
	double A2 = c.x - a.x, B2 = c.y - a.y, C2 = (A2 * A2 + B2 * B2) / 2;
	double D = A1 * B2 - A2 * B1;
	ret.x = a.x + (C1 * B2 - C2 * B1) / D;
	ret.y = a.y + (A1 * C2 - A2 * C1) / D;
	return ret;
}

pair<POS, T> MinCoverCircle(vector<POS> points) {
	T r = 0; int pn = points.size();
	if (pn == 0) {
		return pair<POS, T>(POS(0, 0), 0);
	}
	POS ret = points[0]; // the circle center
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
	return pair<POS, T>(ret, r);	
}

int main() {
    int n;
    while (cin >> n && n) {
		vector<POS> points(n);

        for (int i = 0; i < n; i ++) 
            cin >> points[i].x >> points[i].y;
        
        pair<POS, double> ans = MinCoverCircle(points);

        printf("%.2f %.2f %.2f\n", ans.first.x, ans.first.y, ans.second);
    }	
}
