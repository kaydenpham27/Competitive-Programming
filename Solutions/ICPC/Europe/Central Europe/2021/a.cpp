// FPTU UWR
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define int long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 2e6 + 10;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

int N, Q, up[MAXN][30], h[MAXN], child[MAXN];
vector<int> G[MAXN];

void dfs(int u, int par = -1) {
  child[u] = 1;
  for (auto v : G[u]) {
    if (v != up[u][0]) {
      h[v] = h[u] + 1;
      up[v][0] = u;
      for (int j = 1; j <= 20; j ++) {
        up[v][j] = up[up[v][j - 1]][j - 1];
      }
      dfs(v, u);
      child[u] += child[v];
    }
  }
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
  for (int j = 20; j >= 0; j --) {
    if (up[u][j] != up[v][j]) {
      u = up[u][j];
      v = up[v][j];
    }
  }
  return up[u][0];
}

vector<int> queries[MAXN];
int U[MAXN], V[MAXN], ans[MAXN], sum[MAXN];

void solveFor(int u, int v, int lca, int id) {
  int uu = u;
  int vv = v;
  int prev = -1;

  vector<int> cycle;

  sum[lca] = N;

  if (uu != lca) {
    do {
      sum[uu] = child[uu];
      if (prev > 0) sum[uu] -= child[prev];
      cycle.pb(uu);
      // cout << uu << " " << sum[uu] << "\n";
      prev = uu;
      uu = up[uu][0];
      if (uu == lca && prev != -1) sum[lca] -= child[prev];
    } while (uu != lca);
  }

  cycle.pb(lca); 

  if (vv != lca) {
    vector<int>acycle;
    prev = -1;
    do {
      sum[vv] = child[vv];
      if (prev > 0) sum[vv] -= child[prev];
      acycle.pb(vv);
      // cout << vv << " " << sum[vv] << "\n";
      prev = vv;
      vv = up[vv][0];
      if (vv == lca && prev != -1) sum[lca] -= child[prev];
    } while (vv != lca);
    reverse(all(acycle));
    for (auto x : acycle) cycle.pb(x);
  }

  // lca -> u -> v -> prev(lca)

  int sz = (int)cycle.size();
  int d = (sz)/2;
  vector<int> suff(sz + 2, 0);
  for (int i = sz - 1; i >= 0; i --) {
    suff[i] = suff[i + 1] + sum[cycle[i]];
  }
  // for (auto x : cycle) cout << x << " "; cout << "\n";
  for (int i = 0; i < sz; i ++) {
    int mnRg = min(i + d + 1, sz + 1);
    ans[id] += sum[cycle[i]] * suff[mnRg];
    // cout << cycle[i] << " " << sum[cycle[i]] << " " << mnRg << " " << suff[mnRg] << "\n";
  }
}

void dfs1(int lca) {
  // solve for each lca
  for (auto id : queries[lca]) {
    solveFor(U[id], V[id], lca, id);
  }
  
  for (auto v : G[lca]) {
    if (v != up[lca][0]){
      dfs1(v);
    }
  }
}

void Solve(void) {
  cin >> N >> Q;
  for (int i = 1; i < N; i ++) {
    int u, v; cin >> u >> v;
    G[u].pb(v);
    G[v].pb(u);
  }
  dfs(1);

  for (int i = 1; i <= Q; i ++) {
    cin >> U[i] >> V[i];
    int lca = LCA(U[i], V[i]);
    // cout << u << " " << v << " " << lca << "\n";
    queries[lca].pb(i);
  }
  dfs1(1);
  for (int i = 1; i <= Q; i ++) cout << ans[i] << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; // cin >> Tests;    
  for (int i = 1; i <= Tests; i ++) {
    // cout << "Case " << i << ": ";
    Solve();    
  }
}
