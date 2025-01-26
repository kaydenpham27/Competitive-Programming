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
  vector<vector<int>> G(N + 2);
  set<int> s;
  vector<int> pref(N + 1, 0);
  for (int i = 1; i <= N; i ++) {
    int x; cin >> x;
    s.insert(x);
    G[x].pb(i);
    pref[i] = (int)s.size();
  }
  i64 ans = 0;
  for (int i = 1; i <= N; i ++) {
    int sz = (int)G[i].size();
    if (sz >= 2) {
      int r = G[i][sz - 2];
      ans += pref[r - 1] - (sz > 2);
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
