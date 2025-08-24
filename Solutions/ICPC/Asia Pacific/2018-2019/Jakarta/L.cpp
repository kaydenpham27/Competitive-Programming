// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define i128 __int128
#define int long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  
#define sz(x) (int)x.size()

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;
const i64 INF = LLONG_MAX/2;
const int BLOCK_SIZE = 320;

void Min(int &a, int b) {
  if (a > b) a = b;
}

void Solve(void) {
  int K; string S; cin >> K >> S;
  int sz = sz(S);
  vector<vector<int>> f(sz + 2, vector<int> (sz + 2, INF));
  
  f[0][0] = 0;
  for (int i = 1; i <= sz; i ++) {
    int cur = (S[i - 1] - '0') * (1LL << (sz - i));
    for (int j = 0; j <= i; j ++) {
      if ((i - 1 != j) || S[i - 1] == '1') Min(f[i][j], f[i - 1][j] + cur);
      for (int jj = 1; jj <= j; jj ++) {
        int div = (1LL << jj);
        Min(f[i][j], (f[i - jj][j - jj] / div));
      }
    }
  }

  for (int j = 0; j <= sz; j ++) {
    if (f[sz][j] <= K) {
      cout << j << "\n";
      return;
    }
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