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

int S, T, N, M, tin[MAXN], low[MAXN], counter = 0;
vector<pair<int, int>> G[MAXN], NG[MAXN];
vector<int> path;

int numCC = 0;
int lab[MAXN];
void dfs(int u, int par = -1) {
  tin[u] = low[u] = ++counter;
  path.pb(u);

  bool found = false;
  for (auto [v, w] : G[u]) {
    if (v == par && !found) {
      found = true;
      continue;
    }
    if (!tin[u]) {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
    } else {
      low[u] = min(low[u], tin[v]);
    }
  }

  if (tin[u] == low[u]) {
    numCC ++;
    int v;
    do {
      v = path.back();
      path.pop_back();
      lab[v] = numCC;
    } while (v != u);
  }
}

void Solve(void) {
  cin >> N >> M >> S >> T;
  if (S > T) swap(S, T);
  for (int i = 1; i <= M; i ++) {
    int u, v, w; cin >> u >> v >> w;
    G[u].pb(mp(v, w));
    G[v].pb(mp(u, w));
  }

  for (int i = 1; i <= N; i ++) {
    if (i == T && !tin[i]) {
      cout << -1 << "\n";
      return;
    }
    if (!tin[i]) {
      dfs(i);
    }
  }

  for (int u = 1; u <= N; u ++) {
    for (auto [v, w] : G[u]) {
      if (lab[u] != lab[v]) {
        NG[lab[u]].pb(mp(lab[v], w));
        NG[lab[v]].pb(mp(lab[u], w));
      }
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
