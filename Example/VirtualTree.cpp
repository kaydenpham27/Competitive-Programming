/*
  Problem: https://codeforces.com/contest/1929/problem/E
  Category: Virtual / Auxiliary Tree
*/
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define int long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
int N, counter = 0, addMask[100005], f[(1 << 20) + 10], tin[100005], h[100005], up[100005][25];
vector<int> G[100005];
void dfs(int u) {
  tin[u] = ++counter;
  for (auto v : G[u]) {
    if (v != up[u][0]) {
      h[v] = h[u] + 1;
      up[v][0] = u;
      for (int j = 1; j <= 20; j ++) {
        up[v][j] = up[up[v][j - 1]][j - 1];
      }
      dfs(v);
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
void Solve(void) {
  cin >> N;
  for (int i = 1; i <= N; i ++) {
    G[i].clear();
    addMask[i] = 0;
  }
  for (int i = 1; i < N; i ++) {
    int u, v; cin >> u >> v;
    G[u].pb(v); G[v].pb(u);
  } counter = 0, h[1] = 0, dfs(1);
  vector<int> virtualVer;
  int K; cin >> K;
  for (int i = 0; i < K; i ++) {
    int u, v; cin >> u >> v;
    virtualVer.pb(u); virtualVer.pb(v);
    int lca = LCA(u, v);
    int uu = -1, vv = -1;
    while (u != lca) {
      addMask[u] |= (1 << i);
      uu = u;
      u = up[u][0];
    } 
    while (v != lca) {
      addMask[v] |= (1 << i);
      vv = v;
      v = up[v][0];
    }
    // if (uu != -1) virtualVer.pb(uu);
    // if (vv != -1) virtualVer.pb(vv);
  } 
  sort(all(virtualVer), [&](int u, int v) {return tin[u] < tin[v];});
  int sz = (int)virtualVer.size();
  for (int i = 0; i < sz - 1; i ++) {
    virtualVer.pb(LCA(virtualVer[i], virtualVer[i + 1]));
  }
  sort(all(virtualVer), [&](int u, int v) {return tin[u] < tin[v];});
  virtualVer.erase(unique(all(virtualVer)), virtualVer.end());  
  for (int mask = 0; mask < (1 << K); mask ++) f[mask] = N; f[0] = 0;
  for (auto v : virtualVer) {
    for (int mask = (1 << K) - 1; mask >= 0; mask --) {
      int nxt = (mask | addMask[v]);
      f[nxt] = min(f[nxt], f[mask] + 1);
    }
  }
  cout << f[(1 << K) - 1] << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; cin >> Tests;
  while (Tests --) {
    Solve();
  }
}
