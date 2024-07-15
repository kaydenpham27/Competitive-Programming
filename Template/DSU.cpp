struct DSU{
    int N, ccp;
    vector<int> lab, sz;
    vector<int64_t> sum;
    DSU(int _N) : N(_N), ccp(_N), sum(N + 5, 0), sz(_N + 5, 1), lab(_N + 5) {
        for (int i = 1; i <= N; i ++) {
            lab[i] = i;
        }
    }; 
    int findLab(int u) { return (u == lab[u] ? u : lab[u] = findLab(lab[u])); }
    bool unite(int u, int v, int64_t w) {
        int labu = findLab(u);
        int labv = findLab(v);
        if (labu == labv) return false;
        if (sz[labu] < sz[labv]) swap(labu, labv);
        sz[labu] += sz[labv];
        lab[labv] = labu;
        sum[labu] += sum[labv] + w;
        ccp --;
        return true;
    }
};
