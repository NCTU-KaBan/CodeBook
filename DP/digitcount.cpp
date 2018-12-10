int DP[10000][10];
void Build() {
	int i, tn;
	memset(DP, 0, sizeof(DP));
	for(i = 1; i < 10000; i++) {
		memcpy(DP[i], DP[i-1], 40);
		tn = i;
		while(tn)	DP[i][tn%10]++, tn /= 10;
	}
}
