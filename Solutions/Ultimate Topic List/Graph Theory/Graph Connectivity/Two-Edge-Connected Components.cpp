// FPTU UWR
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 4e5 + 10;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

int N, M, tin[MAXN], low[MAXN], counter = 0;
vector<int> G[MAXN], path;
vector<vector<int>> ans;

void dfs(int u, int par = -1) {
  tin[u] = low[u] = ++counter;
  path.pb(u);

  bool found = false;
  for (auto v : G[u]) {
    if (v == par && !found) {
      found = true;
      continue;
    }
    if (!tin[v]) {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
    } else {
      low[u] = min(low[u], tin[v]);
    }
  }

  if (tin[u] == low[u]) {
    int v;
    vector<int> CC2;
    do {
      v = path.back();
      path.pop_back();
      CC2.pb(v);
    } while (v != u);
    ans.pb(CC2);
  }
}

void Solve(void) {
  cin >> N >> M;
  for (int i = 0; i < M; i ++) {
    int u, v; cin >> u >> v;
    G[u].pb(v);
    G[v].pb(u);
  }

  for (int i = 0; i < N; i ++) {
    if (!tin[i]) {
      dfs(i);
    }
  }

  cout << (int)ans.size() << "\n";
  for (auto cc2 : ans) {
    cout << (int)cc2.size() << " ";
    for (auto u : cc2) cout << u << " ";
    cout << "\n";
  }
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
