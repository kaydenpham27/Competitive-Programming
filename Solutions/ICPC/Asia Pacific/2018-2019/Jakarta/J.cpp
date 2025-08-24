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

void Solve(void) {
  int N; cin >> N;
  vector<string> S(N);
  vector<unordered_map<string, bool>> have(N + 2); 
  map<string, int> ss;
  for (int i = 0; i < N; i ++) {
    cin >> S[i];
    int sz = sz(S[i]);
    for (int mask = 1; mask < (1 << sz); mask ++) {
      string cur = "";
      for (int b = 0; b < sz; b ++) {
        if (mask >> b & 1) {
          cur += S[i][b];
        }
      }
      have[i][cur] = true;
      ss[cur] ++;
    }
  }

  int tot = sz(ss);
  vector<vector<int>> f(tot + 2, vector<int> (N + 2, -1));
  f[0][0] = 0;
  int i = 1;
  for (auto [s, cnt] : ss) {
    f[i][0] = 0;
    for (int j = 1; j <= N; j ++) {
      if (f[i - 1][j - 1] != -1 && (have[j - 1].find(s) != have[j - 1].end())) {
        f[i][j] = f[i - 1][j - 1] + sz(s);
      }
      f[i][j] = max(f[i - 1][j], f[i][j]);
    }
    i ++;
  }
  cout << f[tot][N] << "\n";
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