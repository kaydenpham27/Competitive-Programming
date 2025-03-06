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

const int MAXN = 100;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

vector<int> G[MAXN]; int deg[MAXN], tin[MAXN], low[MAXN], counter = 0;
vector<int> path;
void dfs(int u, int par = -1) {
  path.pb(u);
  tin[u] = low[u] = ++counter;
  for (auto v : G[u]) {
    if (v == par) {
      cout << "NO" << "\n";
      exit(0);
    }
    if (tin[v]) {
      low[u] = min(low[u], tin[v]);
    } else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
    }
  }
  while (low[u] == tin[u]) {
    
  }
}
void Solve(void) {
  int N, M; cin >> N >> M;
  for (int i = 1; i <= M; i ++) {
    int a, b; cin >> a >> b;
    G[a].pb(b);
    deg[b] ++;
  }
  for (int i = 1; i <= N; i ++) {
    if (deg[i]) {
      dfs(i);
    }
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
