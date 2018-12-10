LL extgcd(LL a, LL b, LL &x, LL &y){
    LL d = a;
    if (b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else x = 1, y = 0;
    return d;
}
LL modInv(LL a, LL m){
    LL x, y, d = extgcd(a, m, x, y);
    return d == 1 ? (m + x % m) % m : -1;
}
LL gcd(LL x, LL y){ return y ? gcd(y, x % y) : x; }
typedef pair<LL, LL> pLL;
pLL CRT(LL *A, LL *B, LL *M, int n){
    // A[i]x = B[i] (mod M[i]); F : ans, S : lcm of M;
    LL x = 0, m = 1;
    for (int i = 0 ; i < n ; i++){
        LL a = A[i] * m, b = B[i] - A[i] * x, d = gcd(M[i], a);
        if (b % d) return pLL(0, -1);
        LL t = b / d * modInv(a / d, M[i] / d) % (M[i] / d);
        x = x + m * t;
        m *= M[i] / d;
    }
    x = (x % m + m) % m;
    return pLL(x, m);
}
