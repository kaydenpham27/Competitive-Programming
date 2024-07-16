struct MergeTree {
  vector<vector<int>> st;
  MergeTree(int _N) : st(_N * 4) {}
  vector<int> Combine(vector<int> lf, vector<int> rg) {
    vector<int> res;
    merge(all(lf), all(rg), back_inserter(res));
    res.erase(unique(all(res)), res.end());
    return res;
  }
  void Build(int id, int l, int r) {
    if (l == r) {
      st[id] = {a[l]}; 
      return;
    }
    int mid = (l + r)/2;
    Build(id * 2, l, mid);
    Build(id * 2 + 1, mid + 1, r);
    merge(all(st[id * 2]), all(st[id * 2 + 1]), back_inserter(st[id]));
  }
  vector<int> Get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return {};
    if (u <= l && r <= v) return st[id];
    int mid = (l + r)/2;
    return Combine(Get(id * 2, l, mid, u, v), Get(id * 2 + 1, mid + 1, r, u, v)); 
  }
};
