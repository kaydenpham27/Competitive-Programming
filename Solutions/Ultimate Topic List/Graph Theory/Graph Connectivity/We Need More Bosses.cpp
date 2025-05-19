#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
int N, M, counter = 0, tin[300005], low[300005]; vector<int> G[300005]; vector<pair<int, int>> NG[300005];
void dfs(int u, int par = -1) {
  tin[u] = low[u] = ++counter;
  for (auto v : G[u]) {
    if (v == par) continue;
    if (tin[v] == 0) {
      dfs(v, u);
      bool bridge = false;
      low[u] = min(low[u], low[v]);
      if (low[v] == tin[v]) bridge = true;
      NG[u].pb(mp(v, bridge));
    } else {
      low[u] = min(low[u], tin[v]);
    }
  }
}
int h[300005], ans = 0;
void dfs1(int u, int par = -1) {
  int h1 = 0, h2 = 0;
  for (auto [v, w] : NG[u]) {
    if (v != par) {
      // cout << u << " " << v << " " << w << "\n";
      dfs1(v, u);
      h[u] = max(h[u], h[v] + w);
      if (h[v] + w > h1) {
        h2 = h1;
        h1 = h[v] + w;
      } else {
        h2 = max(h2, h[v] + w);
      }
    }
  }
  ans = max(ans, h1 + h2);
}
void Solve(void) {
  cin >> N >> M;
  for (int i = 1; i <= M; i ++) {
    int u, v; cin >> u >> v;
    G[u].pb(v);
    G[v].pb(u);
  } dfs(1); dfs1(1);
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; // cin >> Tests;
  while (Tests --) {
    Solve();
  }
}