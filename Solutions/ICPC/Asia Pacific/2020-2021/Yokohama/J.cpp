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

const int MAXN = 2e5 + 5;
const int MAXW = 1e6;

int N, M, ans = 0; bool blocked[MAXN]; vector<int> G[MAXN];
void dfs(int u, int par = -1) {
  int child = 0;
  if (!blocked[u]) {
    ans ++;
    for (auto v : G[u]) {
      if (v != par) {
        dfs(v, u);
      }
    }
    return;
  }

  for (auto v : G[u]) {
    if (v != par && !blocked[v]) {
      child ++;
    }
  }
  if (child > 1) {
    blocked[u] = false;
    ans ++;
    for (auto v : G[u]) {
      if (v != par) {
        dfs(v, u);
      }
    }
  } if (child == 1) {
    ans ++;
    for (auto v : G[u]) {
      if (v != par) {
        if (!blocked[v]) blocked[v] = true;
        dfs(v, u);
      }
    }
  }
}
void Solve(void) {
  cin >> N >> M;
  for (int i = 1; i < N; i ++) {
    int u, v; cin >> u >> v;
    G[u].pb(v); G[v].pb(u);
  }
  for (int i = 1; i <= M; i ++) {
    int x; cin >> x; blocked[x] = true;
  }
  dfs(1);
  cout << ans << "\n";
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