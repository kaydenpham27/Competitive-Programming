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

const int MAXN = 5e5 + 10;
const int MOD = 1000000007;
const i64 INF = LLONG_MIN/2;

vector<i64> preCalc;

struct SCC {
  int N, counter, numSCC;
  vector<vector<int>> scc;
  vector<vector<pair<int, int>>> G, NG;
  vector<int> lab, vis, tin, low, path, sum, f; 
  SCC (int _N) {
    N = _N;
    counter = 0;
    numSCC = 0;
    G.resize(N + 2);
    scc.resize(N + 2);
    lab.resize(N + 2, -1);
    tin.resize(N + 2, 0);
    low.resize(N + 2, 0);
    vis.resize(N + 2, false);
    f.resize(N + 2, -1);
  }

  void add_edge(int u, int v, int w) { G[u].pb(mp(v, w)); } 

  void dfs(int u) {
    tin[u] = low[u] = ++counter;
    path.pb(u);
    for (auto [v, w] : G[u]) {
      // Skip vertice from different scc
      if (vis[v]) continue;
      if (!tin[v]) {
        dfs(v);
        low[u] = min(low[u], low[v]);
      } else {
        low[u] = min(low[u], tin[v]);
      }
    }

    if (low[u] == tin[u]) {
      numSCC ++;
      int v; do {
        v = path.back();
        path.pop_back();
        vis[v] = true;
        lab[v] = numSCC;
        scc[numSCC].pb(v);
      } while (v != u);
    }
  }  

  void find_scc(void) {
    for (int i = 1; i <= N; i ++) {
      if (!vis[i]) {
        dfs(i);
      }
    }
  }

  void dfs2(int u) {
    f[u] = sum[u];
    for (auto [v, w] : NG[u]) {
      if (f[v] == -1) dfs2(v);
      f[u] = max(f[u], f[v] + w + sum[u]);
    }
  }

  int query(int st) {
    sum.resize(numSCC + 2, 0LL);
    NG.resize(numSCC + 2);

    for (int u = 1; u <= N; u ++) {
      for (auto [v, w] : G[u]) {
        if (lab[u] == lab[v]) {
          int sz = sqrt(2 * w);
          if (sz * (sz + 1) > 2 * w) sz --;
          sum[lab[u]] += w * (sz + 1) - preCalc[sz];
        } else {
          NG[lab[u]].pb(mp(lab[v], w));
        }
      }
    }

    for (int i = 1; i <= numSCC; i ++) {
      if (f[i] == -1) {
        dfs2(i);
      }
    }
    return f[lab[st]];
  }
};

void Solve(void) {
  int N, M; cin >> N >> M;
  SCC forest(N);
  for (int i = 1; i <= M; i ++) {
    int u, v, w; cin >> u >> v >> w;
    forest.add_edge(u, v, w);
  }
  int st; cin >> st;
  preCalc.pb(0);
  for (int i = 1; i <= 15000; i ++) {
    i64 cur = preCalc.back() + i * (i - 1)/2 + i;
    preCalc.pb(cur);
  }
  forest.find_scc();
  cout << forest.query(st) << "\n";
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
