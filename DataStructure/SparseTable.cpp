struct SparseTable{
    vector<vector<int> > data;
    SparseTable(int *arr, int n){
        int lgN = ceil(__lg(n)) + 1;
        data.resize(lgN);
        for (int i = 0 ; i < n ; i++) data[0].PB(arr[i]);
        for (int h = 1 ; h < lgN ; h++){
            int len = 1 << (h-1), i = 0;
            for (; i + len < n ; i++)
                data[h].PB(max(data[h-1][i], data[h-1][i+len]));
            if (!i) break;
            for (; i < n ; i++)
                data[h].PB(data[h-1][i]);
        }
    }
    int query(int l, int r){
        int h = __lg(r - l);
        int len = 1 << h;
        return op(data[h][l], data[h][r-len]);
    }
};
