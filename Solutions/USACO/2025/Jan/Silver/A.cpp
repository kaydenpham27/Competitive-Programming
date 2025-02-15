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

const int MAXN = 3e6 + 10;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

void Solve(void) {
  int N; cin >> N;
  vector<int> a(N), b(N), pref(N, 0);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  vector<vector<int>> pa(N + 1), pb(N + 1);
  for (int i = 0; i < N; i ++) {
    pa[a[i]].pb(i + 1);
    pb[b[i]].pb(i + 1);
    pref[i] = (i ? pref[i - 1] : 0);
    pref[i] += (a[i] == b[i]);
  }
  vector<vector<i64>> prefa(N + 1), prefb(N + 1);
  for (int i = 1; i <= N; i ++) {
    int sz = pa[i].size();
    prefa[i].resize(sz);
    for (int j = 0; j < sz; j ++) {
      prefa[i][j] = (j ? prefa[i][j - 1] : 0);
      prefa[i][j] += pa[i][j] + ;
    }
    sz = pb[i].size();
    prefb[i].resize(sz);
    for (int j = 0; j < sz; j ++) {
      prefb[i][j] = (j ? prefb[i][j - 1] : 0);
      prefb[i][j] += pb[i][j] + 1;
    }
  }

  i64 ans = 0;
  for (int i = 0; i < N; i ++) {
    int x = min(i + 1, N - i);
    int p = upper_bound(all(pb[a[i]]), x) - pb[a[i]].begin() - 1;
    int pp = upper_bound(all(pb[a[i]]), i + 1) - pb[a[i]].begin() - 1;
    // cout << i << " " << p << " " << pp << "\n";
    if (p >= 0) ans += prefb[a[i]][p];
    ans += (pp - p) * (N - i);
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