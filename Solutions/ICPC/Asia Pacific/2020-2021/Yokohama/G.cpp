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

const int MAXN = 3e5 + 10;
const i64 INF = INT_MAX/2;

struct DSU{
  int N, ccp, tot;
  vector<int> lab, sz;
  vector<int64_t> sum;
  DSU(int _N) : N(_N), ccp(0), tot(0), sum(N + 5, 0), sz(_N + 5, 1), lab(_N + 5) {
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
int N, M, l[MAXN];
void Solve(void) {  
  cin >> N >> M;
  vector<pair<int, int>> ls;
  vector<vector<int>> G(N + 2);
  for (int i = 1; i <= N; i ++) {
    cin >> l[i];
    ls.pb(mp(l[i], i));
  }
  sort(all(ls));
  vector<pair<int, int>> edges;
  for (int i = 1; i <= M; i ++) {
    int u, v; cin >> u >> v;
    edges.pb(mp(u, v));
    G[u].pb(v);
    G[v].pb(u);
  }
  for (int i = 1; i <= N; i ++) {
    sort(all(G[i]), [&](const int &p, const int &q) {
      return l[p] < l[q];
    });
  }

  DSU ver(N);
  vector<pair<int, int>> group(N + 2);
  vector<int> nxt(N + 1, N);
  for (int i = N - 1; i >= 0; i --) {
    auto [val, u] = ls[i];
    ver.ccp ++; ver.tot ++;
    while (!G[u].empty() && l[G[u].back()] >= l[u]) {
      int uu = ver.findLab(u);
      ver.unite(uu, G[u].back(), 0);
      G[u].pop_back();
    }
    if (i < N - 1) {
      if (val < ls[i + 1].first) nxt[i] = i + 1;
      else nxt[i] = nxt[i + 1];
    }
    group[i] = mp(ver.tot, ver.ccp);
  }

  for (int i = 1; i <= N; i ++) G[i].clear();
  for (auto [u, v] : edges) {
    G[u].pb(v); G[v].pb(u);
  }
  for (int i = 1; i <= N; i ++) {
    sort(all(G[i]), [&](const int &p, const int &q) {
      return l[p] > l[q];
    });
  }
  DSU ver1(N);
  int ans = INT_MAX;
  for (int i = 0; i < N; i ++) {
    auto [val, u] = ls[i];
    ver1.ccp ++; ver1.tot ++;
    while (!G[u].empty() && l[G[u].back()] <= l[u]) {
      int uu = ver1.findLab(u);
      ver1.unite(uu, G[u].back(), 0);
      G[u].pop_back();
    }
    int id = nxt[i];
    if (id != N && id == i + 1) {
      auto [tot, ccp] = group[id];
      // cout << id << "\n";
      // cout << ver1.tot << " " << ver1.ccp << " " << tot << " " << ccp << "\n";
      if (tot - ccp + 1 >= ver1.ccp && ver1.tot - ver1.ccp + 1 >= ccp) ans = min(ans, val);
      if (ver1.tot - ver1.ccp + 1 >= ccp && tot - ccp + 1 >= ver1.ccp) ans = min(ans, val);      
    }
  }  
  cout << (ans == INT_MAX ? -1 : ans) << "\n";
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
