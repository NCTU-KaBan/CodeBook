#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL modMul(LL a, LL b, LL m){
    a %= m, b %= m;
    LL y = (LL)((double)a * b/ m + .5);
    LL r = (a * b - y * m) % m;
    return r < 0 ? r + m : r;
}
template <typename T>
inline T pow(T a, T b, T mod){
    T ans = 1;
    for (; b; a = modMul(a, a, mod), b >>= 1)
    if (b%2) ans = modMul(ans, a, mod);
    return ans;
}
int sprp[3] = {2, 7, 61};
int llsprp[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
template <typename T>
inline bool isPrime(T n, int *sprp, int num){
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    int t = 0;
    T u = n - 1;
    for (; u % 2 == 0; t++) u >>= 1;
    for (int i = 0 ; i < num ; i++){
        T a = sprp[i] % n;
        if (a == 0 || a == 1 || a == n-1) continue;
        T x = pow(a, u, n);
        if (x == 1 || x == n-1) continue;
        for (int j = 1 ; j < t ; j++){
            x = modMul(x, x, n);
            if (x == 1) return false;
            if (x == n - 1) break;
        }
        if (x == n - 1) continue;
        return false;
    }
    return true;
}
// does not work when n is prime
long long modit(long long x,long long mod) {
	if(x>=mod) x-=mod;
	//if(x<0) x+=mod;
	return x;
}
long long mult(long long x,long long y,long long mod) {
	long long s=0,m=x%mod;
	while(y) {
		if(y&1) s=modit(s+m,mod);
		y>>=1;
		m=modit(m+m,mod);
	}
	return s;
}
long long f(long long x,long long mod) {
	return modit(mult(x,x,mod)+1,mod);
}
long long pollard_rho(long long n) {
	if(!(n&1)) return 2;
  while (true) {
    long long y=2, x=rand()%(n-1)+1, res=1;
    for (int sz=2; res==1; sz*=2) {
      for (int i=0; i<sz && res<=1; i++) {
        x = f(x, n);
        res = __gcd(abs(x-y), n);
      }
      y = x;
    }
    if (res!=0 && res!=n) return res;
  }
}
int main() {
    int t; cin >> t; while (t--) {
        LL n; cin >> n;
        cout << n << " = ";
        bool first = true;
        map<LL, int> cnt;
        while (!isPrime(n, llsprp, 7)) {
            LL res = pollard_rho(n);
            while (!isPrime(res, llsprp, 7))
                res = pollard_rho(res);
            cnt[res]++;
            n /= res;
        }
        cnt[n]++;
        for (auto &p : cnt) {
            if (first) first = false;
            else cout << " * ";
            cout << p.first;
            if (p.second != 1)
                cout << '^' << p.second;
        }
        cout << '\n';
    }
}
