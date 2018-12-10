// ONE BASE!!
const int MAXN = 5e4 + 5;
struct BIT{
    int data[MAXN], n;
    BIT(int *arr, int _n){ n = _n;
        memset(data, 0, sizeof(data));
        for (int i = 1 ; i <= n ; i++)
            add(i, arr[i]);
    }
    int lowbit(int x) { return x & (-x); }
    int sum(int x){
        int res = 0;
        while (x > 0) res += data[x], x -= lowbit(x);
        return res;
    }
    void add(int x, int d){
        while (x <= n) data[x] += d, x += lowbit(x);
    }
};
