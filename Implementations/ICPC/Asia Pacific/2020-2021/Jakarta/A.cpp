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

const int MAXN = 2e5 + 10;
const int MOD = 235813;
const i64 INF = INT_MAX/2;

int N, a[MAXN], b[MAXN];
void Maximize(pair<int, int> &a, pair<int, int> b) {
  if (a.first < b.first) a = b;
  else if (a.first == b.first) a.second = max(a.second, b.second);
}
void Solve(void) {  
  cin >> N;
  vector<int> pref(N + 3, 0);
  for (int i = 1; i <= N; i ++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }
  for (int i = 1; i <= N; i ++) cin >> b[i];
  vector<vector<pair<int, int>>> f(N + 2, vector<pair<int, int>> (N * 10 + 5, mp(-1, -1)));
  auto calc = [&](int L, int H, int t, int have) {
    int l = L, h = H;
    while (l <= h) {
      int mid = (l + h)/2;
      if (pref[mid] - pref[L] <= t + have) {
        l = mid + 1;
      } else {
        h = mid - 1;
      }
    }
    if (h == H) return mp(h, 0LL);
    return mp(h, t + have - (pref[h] - pref[L]));
  };
  f[1][b[1]] = mp(0LL, 0LL);
  for (int i = 2; i <= N; i ++) {
    for (int t = b[1]; t <= N * 10; t ++) {
      // f[i][j] = f[i - 1][j - bi];
      if (t >= b[i] && f[i - 1][t - b[i]] != mp(-1LL, -1LL)) {
        auto [id, need] = f[i - 1][t - b[i]];
        Maximize(f[i][t], calc(id, i - 1, b[i], need));
        // cout << i << " " << t << " " << f[i][t].first << " " << f[i][t].second << "\n";
      }
      if (t >= b[i] && f[i - 2][t - b[i]] != mp(-1LL, -1LL)) {
        auto [id, need] = f[i - 2][t - b[i]];
        Maximize(f[i][t], calc(id, i - 1, b[i], need));
      }
      // cout << i << " " << t << " " << f[i][t].first << " " << f[i][t].second << "\n";
    }
  }
  int ans = LLONG_MAX;
  for (int t = 1; t <= N * 10; t ++) {
    if (f[N][t] != mp(-1LL, -1LL)) {
      ans = min(ans, t + pref[N] - pref[f[N][t].first] - f[N][t].second);
    }
  }
  cout << ans << "\n";
}
signed main() {
  // ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; // cin >> Tests;    
  for (int i = 1; i <= Tests; i ++) {
    // cout << "Case " << i << ": ";
    Solve();    
  }
}