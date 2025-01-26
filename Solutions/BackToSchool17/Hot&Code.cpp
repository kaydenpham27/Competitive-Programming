/*
  Problem: https://dmoj.ca/problem/bts17p7
  Category: Graph 
*/
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
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
    st[id] = st[id * 2] + st[id * 2 + 1];
  }
  i64 get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) return st[id];
    push(id);
    int mid = (l + r)/2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
  }
};
Tree cnt(100005, 0), sum(100005, 0);
int N, Q, counter = 0, heavy[100005], h[100005], head[100005], tin[100005], tout[100005]; 
int up[100005][20];
vector<int> G[100005];
int dfs(int u) {
  int child = 1, bigChild = -1, bigsz = -1;
  for (auto v : G[u]) {
    if (v != up[u][0]) {
      up[v][0] = u;
      h[v] = h[u] + 1;
      for (int j = 1; j <= 18; j ++) {
        up[v][j] = up[up[v][j - 1]][j - 1];
      }
      int sz = dfs(v);
      child += sz;
      if (sz > bigsz) {
        bigsz = sz;
        bigChild = v;
      }
    }
  }
  heavy[u] = bigChild;
  return child;
}
int LCA(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  int gap = h[u] - h[v];
  for (int j = 0; (1 << j) <= gap; j ++) {
    if (gap >> j & 1) {
      u = up[u][j];
    }
  }
  if (u == v) return u;
  for (int j = 18; j >= 0; j --) {
    if (up[u][j] != up[v][j]) {
      u = up[u][j];
      v = up[v][j];
    }
  }
  return up[u][0];
}
bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[v] <= tout[u];
}
void hld(int u, int H) {
  head[u] = H; tin[u] = ++counter;
  if (heavy[u] == -1) {
    tout[u] = counter;
    return;
  }
  hld(heavy[u], H);
  for (auto v : G[u]) {
    if (v != up[u][0] && v != heavy[u]) {
      hld(v, v);
    }
  }
  tout[u] = counter;
}
void Query(int u, int v, int src, int add = 0, int mul = 1) {
  for (; head[u] != head[v]; u = up[head[u]][0]) {
    if (h[head[u]] < h[head[v]]) swap(u, v);
    cnt.update(1, 1, N, tin[head[u]], tin[u], 1 * mul);
    if (mul == 1) sum.update(1, 1, N, tin[head[u]], tin[u], h[src] - add);
    else sum.update(1, 1, N, tin[head[u]], tin[u], -(h[src] + add));
  }
  if (h[u] > h[v]) swap(u, v);
  cnt.update(1, 1, N, tin[u], tin[v], 1 * mul);
  if (mul == 1) sum.update(1, 1, N, tin[u], tin[v], h[src] - add);
  else sum.update(1, 1, N, tin[u], tin[v], -(h[src] + add));
}
void Solve(void) {
  cin >> N >> Q;
  for (int i = 1; i < N; i ++) {
    int u, v; cin >> u >> v;
    G[u].pb(v); G[v].pb(u); 
  } dfs(1); hld(1, 1);
  while (Q --) {
    int a, b, t; cin >> a >> b >> t;
    int lca = LCA(a, b);
    if (is_ancestor(t, lca)) {
      Query(a, b, t);
    } else {
      if (is_ancestor(lca, t)) {
        int lca1 = LCA(a, t);
        int d = h[t] - h[lca1];
        Query(a, lca1, lca1, d);
        Query(lca1, lca, lca1, d, -1);
        sum.update(1, 1, N, tin[lca1], tin[lca1], d);

        int lca2 = LCA(b, t);
        d = h[t] - h[lca2];
        Query(b, lca2, lca2, d);
        Query(lca2, lca, lca2, d, -1);
        sum.update(1, 1, N, tin[lca2], tin[lca2], d);
        sum.update(1, 1, N, tin[lca], tin[lca], h[t] - h[lca]);
      } else {
        int lcaa = LCA(lca, t);
        int d = h[lca] + h[t] - 2 * h[lcaa];
        Query(a, b, lca, d);
      }
    }
  }
  for (int i = 1; i <= N; i ++) {
    int C = cnt.get(1, 1, N, tin[i], tin[i]);
    i64 S = sum.get(1, 1, N, tin[i], tin[i]);
    cout << 1LL * h[i] * C - S << " \n"[i == N];
  }
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; // cin >> Tests;
  while (Tests --) {
    Solve();
  }
}
