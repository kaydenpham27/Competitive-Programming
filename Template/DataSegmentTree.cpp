struct DataTree {
  const i64 INF = 1e18;
  struct Data {
    /// Fields
  };
  vector<Data> st;
  Tree (int _N) : st(4 * _N + 4) {}
  Data combine(Data lf, Data rg) {
    Data res;
    // Operations go here
    return res;
  }
  void build(int id, int l, int r) {
    if (l == r) {
      // Base case
      return;
    }
    int mid = (l + r)/2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = combine(st[id * 2], st[id * 2 + 1]);
  }
  void update(int id, int l, int r, int p, i64 x) {
    if (p < l || p > r) return;
    if (l == r) {
      // Base case
      return;
    }
    int mid = (l + r)/2;
    update(id * 2, l, mid, p, x);
    update(id * 2 + 1, mid + 1, r, p, x);
    st[id] = combine(st[id * 2], st[id * 2 + 1]);
  }
  Data get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return {-INF, -INF, INF, INF};
    if (u <= l && r <= v) return st[id];
    int mid = (l + r)/2;
    return combine(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
  }
};
