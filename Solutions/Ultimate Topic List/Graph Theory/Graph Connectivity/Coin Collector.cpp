// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
 
using namespace std;
 
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
 
const int MAXN = 1e5 + 5;
int N, M, tin[MAXN], low[MAXN], lab[MAXN], vis[MAXN];
i64 ans = 0, K[MAXN], sum[MAXN], f[MAXN];
int scc = 0, counter = 0;
vector<int> st, G[MAXN], NG[MAXN];
void dfs(int u) {
  tin[u] = low[u] = ++counter;
  vis[u] = 1;
  st.pb(u);
  for (auto v : G[u]) {
    if (vis[v] == 2) continue;
    if (!tin[v]) {
      dfs(v);
      low[u] = min(low[u], low[v]);
    } else {
      low[u] = min(low[u], tin[v]);
    }
  }
  if (low[u] == tin[u]) {
    int v; scc ++;
    do {
      v = st.back();
      vis[v] = 2;
      lab[v] = scc;
      sum[scc] += K[v];
      st.pop_back();
    } while (v != u);
  }
}
void dfs1(int u) {
  vis[u] = 1;
  f[u] = sum[u];
  for (auto v : NG[u]) {
    if (!vis[v]) {
      dfs1(v);
    }
    f[u] = max(f[u], f[v] + sum[u]);
  }
  ans = max(ans, f[u]);
}
void Solve(void) {
  cin >> N >> M;
  for (int i = 1; i <= N; i ++) cin >> K[i];
  for (int i = 1; i <= M; i ++) {
    int u, v; cin >> u >> v;
    G[u].pb(v);
  } 
  for (int i = 1; i <= N; i ++) {
    if (!tin[i]) dfs(i);
  }
  for (int i = 1; i <= N; i ++) {
    vis[i] = 0;
    for (auto j : G[i]) {
      if (lab[i] != lab[j]) {
        NG[lab[i]].pb(lab[j]);
      }
    }
  }
  for (int i = 1; i <= scc; i ++) {
    if (!vis[i]) {
      dfs1(i);
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}