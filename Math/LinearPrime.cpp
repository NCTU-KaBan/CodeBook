const int MAXN = 1e5 + 5;
vector<bool> isP(MAXN, true);
vector<int> P;
void linear_prime() {
    isP[0] = isP[1] = false;
    for (int i = 2 ; i < MAXN ; i++) {
        if (isP[i]) P.push_back(i);
        for (auto p : P) {
            if (i * p >= MAXN) break;
            isP[i * p] = false;
            if (i % p == 0) break;
        }
    }
}
