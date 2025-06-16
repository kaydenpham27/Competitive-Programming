#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 1e3 + 10;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

void Solve(void) {
  int N, M, L; cin >> N >> M >> L;
  string ops; 
  if (L) cin >> ops;
  vector<vector<char>> g(N + 2, vector<char> (M + 2));
  for (int i = 1; i <= N; i ++) {
    for (int j = 1; j <= M; j ++) {
      cin >> g[i][j];
    }
  }

  for (int s = 0; s < L; s ++) {
    if (ops[s] == 'D') {
      for (int i = N; i >= 1; i --) {
        for (int j = 1; j <= M; j ++) {
          if (g[i][j] != '.') {
            int d = i + 1;
            while (d <= N) {
              if (g[d][j] != '.') break;
              swap(g[d][j], g[d - 1][j]);
              d ++;
            }
          }
        }
      }
    } else if (ops[s] == 'U') {
      for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= M; j ++) {
          if (g[i][j] != '.') {
            int d = i - 1;
            while (d > 0) {
              if (g[d][j] != '.') break;
              swap(g[d][j], g[d + 1][j]);
              d --;
            }
          }
        }
      }
    } else if (ops[s] == 'L') {
      for (int j = 1; j <= M; j ++) {
        for (int i = 1; i <= N; i ++) {
          if (g[i][j] != '.') {
            int d = j - 1;
            while (d > 0) {
              if (g[i][d] != '.') break;
              swap(g[i][d], g[i][d + 1]);
              d --;
            }
          }
        }
      }
    } else {
      for (int j = M; j >= 1; j --) {
        for (int i = 1; i <= N; i ++) {
          if (g[i][j] != '.') {
            int d = j + 1;
            while (d <= M) {
              if (g[i][d] != '.') break;
              swap(g[i][d], g[i][d - 1]);
              d ++;
            }
          }
        }
      }      
    }

    // for (int i = 1; i <= N; i ++) {
    //   for (int j = 1; j <= M; j ++) {
    //     cout << g[i][j];
    //   }
    //   cout << "\n";
    // }
    // cout << "\n";
  }

  for (int i = 1; i <= N; i ++) {
    for (int j = 1; j <= M; j ++) {
      cout << g[i][j];
    }
    cout << "\n";
  }
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
