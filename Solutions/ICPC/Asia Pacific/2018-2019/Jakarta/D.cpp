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
  int N, M; cin >> N >> M;
  vector<vector<char>> g(N + 2, vector<char> (M + 2));
  int ans = 0;
  for (int i = 1; i <= N; i ++) {
    for (int j = 1; j <= M; j ++) {
      cin >> g[i][j];
      if (i > 1 && i < N && j > 1 && j < M) {
        ans += g[i][j] == '.';
      }
    }
  }
  if (N == 1) for (int j = 2; j < M; j ++) ans += (g[1][j] == '.');
  if (N == 2) for (int j = 2; j < M; j ++) ans += (g[1][j] == '.') & (g[2][j] == '.');
  if (M == 1) for (int i = 2; i < N; i ++) ans += (g[i][1] == '.');
  if (M == 2) for (int i = 2; i < N; i ++) ans += (g[i][1] == '.') & (g[i][2] == '.');

  if (N >= 3 && M >= 3) {
    bool have = false;
    for (int i = 2; i < N; i ++) have |= (g[i][1] == '#') || (g[i][M] == '#');
    for (int j = 2; j < M; j ++) have |= (g[1][j] == '#') || (g[N][j] == '#');
    ans += !have;
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