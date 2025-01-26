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

const int MAXN = 2e5 + 5;
const int MAXW = 1e6;

int N, M;
void Solve(void) {
  cin >> N >> M;
  vector<int> a(N + 1), b(M + 1);
  vector<vector<bool>> f(N + 2, vector<bool> (M + 2, false));
  for (int i = 1; i <= N; i ++) cin >> a[i];
  for (int i = 1; i <= M; i ++) cin >> b[i];
  for (int i = 0; i <= N; i ++) {
    for (int j = 0; j <= M; j ++) {
      if (i == 0 && j == 0) f[i][j] = true;
      else {
        if (i && f[i - 1][j] && (a[i] == 0 || a[i] == i + j)) f[i][j] = true;
        if (j && f[i][j - 1] && (b[j] == 0 || b[j] == i + j)) f[i][j] = true;
      }
    }
  }
  int NN = N, MM = M;
  while (N || M) {
    if (N > 0 && f[N - 1][M] && (a[N] == 0 || a[N] == N + M)) {
      a[N] = N + M;
      N --;
    } else {
      b[M] = N + M;
      M --;
    }
  }
  for (int i = 1; i <= NN; i ++) cout << a[i] << " \n"[i == NN];
  for (int i = 1; i <= MM; i ++) cout << b[i] << " \n"[i == MM];
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