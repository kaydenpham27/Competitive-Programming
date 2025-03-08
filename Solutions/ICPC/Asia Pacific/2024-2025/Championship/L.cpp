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
  int R, C, N, P; cin >> R >> C >> N >> P;
  vector<vector<int>> g(R + 2, vector<int> (C + 2)); 

  for (int i = 1; i <= R; i ++) {
    for (int j = 1; j <= C; j ++) {
      cin >> g[i][j];
    }
  }

  int ans = 0;
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  set<int> s;
  for (int i = 1; i <= R; i ++) {
    for (int j = 1; j <= C; j ++) {
      for (int z = 0; z < 4; z ++) {
        int ii = i + dx[z];
        int jj = j + dy[z];
        if (g[i][j] == 0) continue;
        if (ii > 0 && ii <= R && jj > 0 && jj <= C && g[ii][jj]) {
          int gap = g[i][j] - P;
          int neighbor = g[ii][jj] - gap;

          if (gap <= 0 && neighbor > 0 && neighbor <= N && neighbor != P) {
            s.insert(neighbor);
          }
        }
      }
    }
  }

  ans = (int)s.size();
  
  cout << ans << "/" << N - 1 << "\n";
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
