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

const int MAXN = 4e5 + 10;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

struct DSU{
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
vector<pair<int, int>> G[MAXN];
int h[MAXN], up[MAXN][22], mx[MAXN][22][2];
void dfs(int u = 1) {
  for (auto [v, w] : G[u]) {
    if (v != up[u][0]) {
      up[v][0] = u;

      if (w % 2 == 1) {
        mx[v][0][1] = w;
        mx[v][0][0] = INF;
      } else {
        mx[v][0][0] = w;
        mx[v][0][1] = INF;
      }

      h[v] = h[u] + 1;
      for (int j = 1; j <= 20; j ++) {
        up[v][j] = up[up[v][j - 1]][j - 1];
        if (w % 2 == 1) {
          mx[v][j][1] = max({w, mx[v][j - 1][1], mx[up[v][j - 1]][j - 1][1]});
          mx[v][j][0] = max(mx[v][j - 1][0], mx[up[v][j - 1]][j - 1][0]);
        } else {
          mx[v][j][0] = max({w, mx[v][j - 1][0], mx[up[v][j - 1]][j - 1][0]});
          mx[v][j][1] = max(mx[v][j - 1][1], mx[up[v][j - 1]][j - 1][1]);
        }
      }
      dfs(v);
    }
  }
}
int calc(int u, int v, int par) {
  if (h[u] < h[v]) swap(u, v);
  int gap = h[u] - h[v];
  int ans = INF;
  for (int j = 0; (1 << j) <= gap; j ++) {
    if (gap >> j & 1) {
      ans = max(ans, mx[u][j][par]);
      u = up[u][j];
    }
  }
  if (u == v) return ans;
  for (int j = 20; j >= 0; j --) {
    if (up[u][j] != up[v][j]) {
      ans = max(ans, mx[u][j][par]);
      ans = max(ans, mx[v][j][par]);
      u = up[u][j];
      v = up[v][j];
    }
  }
  // cout << u << " " << v << "\n";
  // cout << mx[u][0][par] << " " << mx[v][0][par] << "\n";
  ans = max(ans, mx[u][0][par]);
  ans = max(ans, mx[v][0][par]);
  return ans;
}
void Solve(void) {
  int N, M; cin >> N >> M;
  for (int i = 1; i <= N; i ++) {
    G[i].clear();
    h[i] = 0;
    for (int j = 0; j <= 20; j ++) {
      up[i][j] = 0;
      mx[i][j][0] = mx[i][j][1] = 0;
    }
  }
  vector<array<int, 4>> edges;
  vector<int> used(M + 2, false);
  DSU mst(N);
  for (int i = 1; i <= M; i ++) {
    int u, v, w; cin >> u >> v >> w;
    edges.pb({w, u, v, i});
  }
  sort(all(edges));
  i64 odd = -1, even = -1;
  i64 sum = 0;
  for (auto [w, u, v, id] : edges) {
    if (mst.unite(u, v, w)) {
      used[id] = true;
      G[u].pb(mp(v, w));
      G[v].pb(mp(u, w)); 
      sum += w;
    }
  }

  if (mst.ccp != 1) {
    cout << -1 << " " << -1 << "\n";
    return;
  }
  dfs();
  if (sum % 2 == 1) odd = sum;
  else even = sum;

  // cout << calc(3, 4, 0) << "\n";

  for (auto [w, u, v, id] : edges) {
    i64 dec = calc(u, v, 1 - (w % 2));
    if (used[id]) continue;
    if (dec == INF) continue;
    i64 cur = sum + w - dec;
    if (cur % 2 == 1) {
      odd = (odd == -1 ? cur : min(odd, cur));
    } else {
      even = (even == -1 ? cur : min(even, cur));
    }
  }

  cout << even << " " << odd << "\n";
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
