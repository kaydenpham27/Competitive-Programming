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
  int N, A, B; cin >> N >> B >> A;
  vector<vector<char>> g(N, vector<char>(N));
  for (int i = 0; i < N; i ++) {
    for (int j = 0; j < N; j ++) {
      cin >> g[i][j];
    }
  }

  vector<vector<bool>> marked(N, vector<bool> (N, false));
  for (int i = 0; i < N; i ++) {
    for (int j = 0; j < N; j ++) {
      if (g[i][j] == 'B') {
        if (i >= A && j >= B) {
          if (g[i - A][j - B] == 'W') {
            cout << -1 << "\n";
            return;
          }
          marked[i - A][j - B] = true;
          marked[i][j] = true;
        } else {
          cout << -1 << "\n";
          return;
        }
      } else if (g[i][j] == 'G') {
        if (i >= A && j >= B) {
          if (!marked[i - A][j - B]) marked[i][j] = true;
        } else {
          marked[i][j] = true;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i ++) {
    for (int j = 0; j < N; j ++) {
      ans += marked[i][j];
    }
  }
  cout << ans << "\n";
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