LL CountDigit(LL n, int x) {
	LL ret = 0;
    for (LL m = 1 ; m <= n ; m *= 10)
        if (x != 0)
            ret += (n / m + 9 - x) / 10 * m + (n / m % 10 == x) * (n % m + 1);
        else
            ret += (n / m - 1) / 10 * m + (n / m % 10 == 0) * (n % m + 1);
    return ret;
}
