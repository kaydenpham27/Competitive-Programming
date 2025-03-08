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

const int MAXN = 4e5 + 10;
const int MOD = 998244353;
const i64 INF = INT_MAX/2;

void Solve(void) {
  int N; cin >> N;
  vector<int> a(N + 2);
  for (int i = 1; i <= N; i ++) {
    int x; cin >> x;
    a[x] = i;
  }

  vector<vector<int>> f(N + 2, vector<int> (N + 2, 0));
  for (int l = N; l >= 1; l --) {
    for (int r = l; r <= N; r ++) {
      f[l][r] = INF;
      if (l == r) f[l][r] = 0;
      else if (l == r - 1) f[l][r] = abs(a[l] - a[r]);
      else {
        for (int m = l; m < r; m ++) {
          int cost = abs(a[l] - a[m + 1]);
          f[l][r] = min(f[l][r], f[l][m] + f[m + 1][r] + cost);
        }
      }
    }
  }

  cout << f[1][N] << "\n";
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
