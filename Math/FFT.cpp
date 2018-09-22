#include <bits/stdc++.h>
using namespace std;
typedef double D;
const D PI = acos(-1.0);
struct C{
    D x,y;C(){x=0,y=0;}C(D x,D y):x(x),y(y){}
    C operator+(const C&c){return C(x+c.x,y+c.y);}
    C operator-(const C&c){return C(x-c.x,y-c.y);}
    C operator*(const C&c){return C(x*c.x-y*c.y,x*c.y+y*c.x);}
};
void FFT(vector<C> &c, int t) {
    int n = c.size();
	for (int i = 1, j = 0 ; i < n ; i++) {
		for (int k = (n >> 1) ; k > (j ^= k) ; k >>= 1);
		if (i < j) swap(c[i], c[j]);
	}
	for (int m = 2 ; m <= n ; m <<= 1) {
		C wm(cos(2 * PI * t / m), sin(2 * PI * t / m));
		for (int k = 0 ; k < n ; k += m) {
			C w(1.0, 0.0);
			for (int j = 0 ; j < (m >> 1) ; j++) {
				C u = c[k + j];
				C t = w * c[k + j + (m >> 1)];
				c[k + j] = u + t;
				c[k + j + (m >> 1)] = u - t;
				w = w * wm;
			}
		}
	}
	if (~t) return;
	for (int i = 0 ; i < n ; i++)
		c[i].x /= n, c[i].y /= n;
}
vector<int> multi(vector<int> &a, vector<int> &b) {
    int maxLen = max(a.size(), b.size());
    int n = 1; while (n < 2 * maxLen) n <<= 1;
    vector<C> A(n), B(n), R(n);
    for (int i = 0 ; i < a.size() ; i++) A[i].x = a[i];
    for (int i = 0 ; i < b.size() ; i++) B[i].x = b[i];
    FFT(A, 1); FFT(B, 1);
    for (int i = 0 ; i < n ; i++) R[i] = A[i] * B[i];
    FFT(R, -1);
    vector<int> ret(n);
    for (int i = 0 ; i < n ; i++) ret[i] = int(R[i].x + .5);
    return ret;
}
int main() { ios_base::sync_with_stdio(false); cin.tie(0);
    stringstream ss;
    string sa; getline(cin, sa);
    string sb; getline(cin, sb);
    vector<int> A, B, C;
    int tmp;
    ss.clear(); ss << sa;
    while (ss >> tmp) A.push_back(tmp);
    ss.clear(); ss << sb;
    while (ss >> tmp) B.push_back(tmp);
    C = multi(A, B);
    for (auto c : C) cout << c << ' '; cout << '\n';
}
