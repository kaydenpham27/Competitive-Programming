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
  vector<vector<int>> Add(N, vector<int> (N, 0));
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  for (int i = 0; i < N; i ++) {
    pref[i] = (i ? pref[i - 1] : 0);
    pref[i] += (a[i] == b[i]);
  }

  for (int i = 0; i < N; i ++) {
    for (int j = 0; j < N; j ++) {
      if (a[i] == b[j]) {
        if (j <= i) Add[j][i] ++;
        else Add[i][j] ++;
      }
    }
  }
  vector<int> ans(N + 1, 0);
  for (int l = N - 1; l >= 0; l --) {
    for (int r = l; r < N; r ++) {
      if (l + 1 < N && r >= 1) Add[l][r] += Add[l + 1][r - 1];
      int cur = 0;
      if (l) cur += pref[l - 1];
      cur += pref[N - 1] - pref[r];
      ans[Add[l][r] + cur] ++;
    }
  }
  for (int i = 0; i <= N; i ++) cout << ans[i] << "\n";
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
