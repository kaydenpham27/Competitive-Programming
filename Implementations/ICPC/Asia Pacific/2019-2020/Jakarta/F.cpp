// FPT UWR
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

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const int MAXN = 4444;
const int INF = 1e9;
const int64_t MOD = (1LL << 61) - 1;
const int64_t BASE = uniform_int_distribution<int64_t>(0, MOD - 1)(rng);
 
__int128 mul(int64_t a, int64_t b) { return (__int128)a * b; }
int64_t mod_mul(int64_t a, int64_t b) { return mul(a, b) % MOD; }

int64_t Pow(int64_t x, int64_t e) {
  int64_t ans = 1;
  while (e) {
    if (e & 1) ans = mod_mul(ans, x);
    x = mod_mul(x, x);
    e >>= 1LL;
  }
  return ans % MOD;
}
int N, h[MAXN], gh[MAXN], gd[MAXN], d[MAXN], c[MAXN]; vector<int> G[MAXN];
void dfs(int u, int par = -1) {
  h[u] = 1;
  for (auto v : G[u]) {
    if (v != par) {
      dfs(v, u);
      d[u] = max(d[u], d[v] + 1);
    }
  }  
  for (auto v : G[u]) {
    if (v != par) {
      i64 add = (c[d[u]] + h[v]) % MOD;
      h[u] = mod_mul(h[u], add);
    }
  }
}
int ans = INT_MIN;
// void dfs1(int u, int par = -1) {
  
// }
void Solve(void) {  
  cin >> N;
  for (int i = 1; i < N; i ++) {
    int u, v; cin >> u >> v;
    G[u].pb(v); G[v].pb(u);
  }
  set<int> s;
  while (true) {
    s.insert(uniform_int_distribution<int64_t>(0, MOD - 1)(rng));
    if ((int)s.size() == N) break;
  }
  for (int i = 1; i <= N; i ++) {
    c[i] = (*s.begin());
    s.erase(s.begin());
  }
  d[0] = INT_MIN; 
  dfs(1); 
  for (int v = 1; v <= N; v ++) {
    
  }

  if (ans == INT_MIN) ans = -1;
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
