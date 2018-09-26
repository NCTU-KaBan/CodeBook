const int MAXN = 1e5 + 5;
vector<bool> isPrime(MAXN, true);
vector<int> mu(MAXN), prime;
void mobius() {
    mu[1] = 1;
    for (int i = 2 ; i < MAXN ; i++) {
        if (isPrime[i]) prime.push_back(i), mu[i] = -1;
        for (auto p : prime) {
            if (i * p >= MAXN) break;
            isPrime[i * p] = mu[i * p] = false;
            if (i % p == 0) break;
            mu[i * p] = -mu[i];
        }
    }
}
