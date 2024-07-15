struct Tree{
    int n;
    vector<int64_t>lazy;
    vector<int64_t>st;
    Tree(int _n, int64_t _v): n(_n), st(_n * 4, _v), lazy(_n * 4, _v){};
    void push(int id){
        int64_t add = lazy[id];
        lazy[id * 2] += add, st[id * 2] += add;
        lazy[id * 2 + 1] += add, st[id * 2 + 1] += add;
        lazy[id] = 0;
    }
    void update(int id, int l, int r, int u, int v, int64_t val){
        if (v < l || u > r) return;
        if (u <= l && r <= v) {
            st[id] += val;
            lazy[id] += val;
            return;
        }
        push(id);
        int mid = (l + r)/2;
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);
        st[id] = min(st[id * 2], st[id * 2 + 1]);
    }
    int find(int id, int l, int r, int u, int v){
        if (v < l || u > r) return 0;
        if (st[id] > 0) return 0;
        if (l == r) return l;
        push(id);
        int mid = (l + r)/2;
        int rg = find(id * 2 + 1, mid + 1, r, u, v);
        if (rg != 0) return rg;
        return find(id * 2, l, mid, u, v);
    }
};
