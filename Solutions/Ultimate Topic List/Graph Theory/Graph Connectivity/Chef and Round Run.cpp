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
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

struct SCC {
  int N, counter, numSCC;
  vector<vector<int>> NG, G, scc;
  vector<int> lab, tin, low, path;
  vector<bool> vis, looped; 
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
    looped.resize(N + 2, false);
  }

  void add_edge(int u, int v) { 
    G[u].pb(v); 
    looped[u] = (u == v);
  } 

  void dfs(int u) {
    tin[u] = low[u] = ++counter;
    path.pb(u);
    for (auto v : G[u]) {
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

  void dfs2(int u, vector<int> &ans) {
    vis[u] = true;
    for (auto v : NG[u]) {
      if (!vis[v]) dfs2(v, ans);
    }
    ans.pb(u);
  }

  vector<int> topo_order(void) {
    vector<int> ans;
    NG.resize(numSCC + 2);
    for (int u = 1; u <= N; u ++) {
      vis[u] = false;
      for (auto v : G[u]) {
        if (lab[u] != lab[v]) {
          NG[lab[u]].pb(lab[v]);
        }
      }
    }

    for (int i = 1; i <= numSCC; i ++) {
      if (!vis[i]) {
        dfs2(i, ans);
      }
    }

    reverse(all(ans));
    return ans;
  }
};

void Solve(void) {
  int N; cin >> N;
  SCC box(N);
  for (int i = 1; i <= N; i ++) {
    int x; cin >> x;
    box.add_edge(i, (i + x) % N + 1);
  }
  int ans = 0;
  box.find_scc();
  for (int i = 1; i <= box.numSCC; i ++) {
    if (box.scc[i].size() > 1) {
      ans += box.scc[i].size();
    } else {
      int u = box.scc[i].back();
      ans += box.looped[u];
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; cin >> Tests;    
  for (int i = 1; i <= Tests; i ++) {
    // cout << "Case " << i << ": ";
    Solve();    
  }
}
