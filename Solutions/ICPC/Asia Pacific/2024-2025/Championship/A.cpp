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

const int MAXN = 4e5 + 10;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

void Solve(void) {
  int N, M; cin >> N >> M;
  vector<vector<char>> g(N + 2, vector<char> (M + 2));
  vector<vector<int>> col(N + 2, vector<int> (M + 2, 0));
  vector<vector<int>> row(N + 2, vector<int> (M + 2, 0));

  for (int i = 1; i <= N; i ++) {
    for (int j = 1; j <= M; j ++) {
      cin >> g[i][j];
    }
  }

  for (int i = 1; i <= N; i ++) {
    for (int j = 1; j <= M; j ++) {
      row[i][j] = row[i][j - 1] + (g[i][j] == '.');
    }
  }

  for (int j = 1; j <= M; j ++) {
    for (int i = 1; i <= N; i ++) {
      col[i][j] = col[i - 1][j] + (g[i][j] == '.');
    }
  }

  i64 ans = 0;

  // same row
  for (int i = 1; i <= N; i ++) {
    int sum3 = 0, sum2 = 0, sum1 = 0;
    for (int j = 1; j <= M; j ++) {
      if (g[i][j] == '.') {
        int have = col[N][j] - 1;
        sum3 += have * (have - 1);
        sum2 += have;
        sum1 ++;
      }
    }

    ans += sum1 * (sum1 - 1) * (sum1 - 2) * (sum1 - 3);

    for (int j = 1; j <= M; j ++) {
      if (g[i][j] == '.') {
        int have = col[N][j] - 1;
        sum3 -= have * (have - 1);
        sum2 -= have;
        sum1 --;

        ans += sum3;
        ans += have * (have - 1) * sum1;
        ans += have * sum2;

        sum3 += have * (have - 1);
        sum2 += have;
        sum1 ++;
      }
    }
  }

  // same col
  for (int j = 1; j <= M; j ++) {
    int sum3 = 0, sum2 = 0, sum1 = 0;
    for (int i = 1; i <= N; i ++) {
      if (g[i][j] == '.') {
        int have = row[i][M] - 1;
        sum3 += have * (have - 1);
        sum2 += have;
        sum1 ++;
      }
    }

    ans += sum1 * (sum1 - 1) * (sum1 - 2) * (sum1 - 3);

    for (int i = 1; i <= N; i ++) {
      if (g[i][j] == '.') {
        int have = row[i][M] - 1;
        sum3 -= have * (have - 1);
        sum2 -= have;
        sum1 --;

        ans += sum3;
        ans += have * (have - 1) * sum1;
        ans += have * sum2;

        sum3 += have * (have - 1);
        sum2 += have;
        sum1 ++;
      }
    }
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
