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
struct DSU {
  int N, ccp;
  vector<int> lab, sz;
  vector<int64_t> sum;
  DSU(int _N) : N(_N), ccp(_N), sum(N + 5, 0), sz(_N + 5, 1), lab(_N + 5) {
    for (int i = 1; i <= N; i ++) {
      lab[i] = i;
    }
  }; 
  int findLab(int u) { return (u == lab[u] ? u : lab[u] = findLab(lab[u])); }
  bool unite(int u, int v, int64_t w) {
    int labu = findLab(u);
    int labv = findLab(v);
    if (labu == labv) return false;
    if (sz[labu] < sz[labv]) swap(labu, labv);
    sz[labu] += sz[labv];
    lab[labv] = labu;
    sum[labu] += sum[labv] + w;
    ccp --;
    return true;
  }
};
struct SCC {
  int N, counter, numSCC;
  vector<vector<int>> NG, G, scc;
  vector<int> lab, tin, low, path, child;
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

    child.resize(N + 2, 0);
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
    child[u] = scc[u].size();
    for (auto v : NG[u]) {
      if (!vis[v]) dfs2(v, ans);
      child[u] += child[v];
    }
    ans.pb(u);
  }

  int query(void) {
    DSU comp(numSCC);

    for (int u = 1; u <= N; u ++) {
      if (scc[lab[u]].size() > 1) {
        int paru = comp.findLab(lab[u]);
        comp.sum[paru] = 1;
      }
      for (auto v : G[u]) {
        if (lab[u] != lab[v]) {
          bool w = (scc[lab[u]].size() > 1) | (scc[lab[v]].size() > 1);
          comp.unite(lab[u], lab[v], w);
        }
      }
    }

    int ans = N;
    vector<bool> used(numSCC + 2, false);
    for (int u = 1; u <= numSCC; u ++) {
      int paru = comp.findLab(u);
      if (used[paru]) continue;
      used[paru] = true;
      if (comp.sum[paru] == 0) ans --;
    }

    return ans;
  }
};

void Solve(void) {
  int N, M; cin >> N >> M;
  SCC city(N);
  for (int i = 1; i <= M; i ++) {
    int u, v; cin >> u >> v;
    city.add_edge(u, v);
  }
  city.find_scc();
  cout << city.query() << "\n";
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
