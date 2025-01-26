// FPT UWR
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 4004;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1e9;
const int64_t MOD = (1LL << 61) - 1;
 
__int128 mul(int64_t a, int64_t b) { return (__int128)a * b; }
int64_t mod_mul(int64_t a, int64_t b) { return mul(a, b) % MOD; }
 

int N, sz[MAXN]; vector<int> G[MAXN];
/// Find potential centroids of the tree
void dfs(int u, int par, int num, vector<int> &points) {
  sz[u] = 1;
  int mx = 0;
  for (auto v : G[u]) {
    if (v != par) {
      dfs(v, u, num, points);
      mx = max(mx, sz[v]);
      sz[u] += sz[v];
    }
  }
  if (mx <= num/2 && num - sz[u] <= num/2) points.pb(u);
}
i64 BASE[MAXN];
pair<int, i64> hashTree(int u, int border, int par = -1) {
  int curD = 0; i64 curH = 1;
  vector<i64> hashes;
  for (auto v : G[u]) {
    if (v != border && v != par) {
      auto [D, H] = hashTree(v, border, u);
      curD = max(curD, D + 1);
      hashes.pb(H);
    }
  }
  for (auto H : hashes) {
    i64 mul = (H + BASE[curD]) % MOD;
    curH = mod_mul(curH, mul);
  }
  return mp(curD, curH);
}
bool solveFor(int root) {
  vector<int> centroids;
  map<i64, i64> Hs;
  for (auto x : G[root]) {
    centroids.clear();
    if (sz[x] < sz[root]) dfs(x, root, sz[x], centroids);
    else dfs(x, root, N - sz[root], centroids);
    i64 prv = -1; 
    for (auto x : centroids) {
      auto [D, H] = hashTree(x, root);
      if (prv != H) Hs[H] ++;
      prv = H;
      // cout << x << " " << H << "\n";
    }
  }
  for (auto [id, v] : Hs) {
    if (v == (int)G[root].size()) {
      return true;
    }
  }
  return false;
}
void Solve(void) {  
  cin >> N;
  for (int i = 1; i <= N; i ++) {
    BASE[i] = uniform_int_distribution<int64_t>(0, MOD - 1)(rng);
  }
  for (int i = 1; i < N; i ++) {
    int u, v; cin >> u >> v;
    G[u].pb(v); G[v].pb(u);
  }
  vector<int> cuttingPoints;
  dfs(1, -1, N, cuttingPoints);
  int ans = -1;
  for (auto x : cuttingPoints) {
    if (solveFor(x)) {
      // cout << x << "\n";
      ans = max(ans, (int)G[x].size());
    }
  }
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
