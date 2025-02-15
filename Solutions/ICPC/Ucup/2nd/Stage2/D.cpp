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
const i64 INF = LLONG_MIN/2;

void dosth(int N, int M) {
  bool swapped = false;
  if (N > M) {
    swap(N, M);
    swapped = true;
  }
  vector<pair<int, int>> ans;
  int d = 2 + (N - 2)/2;
  int st = (N - 2)/2;
  for (int i = 1; i <= N; i ++) {
    ans.pb(mp(i, 1));
    ans.pb(mp(i, M));
  }
  for (int j = 1 + d; j <= M - d; j += 2) {
    for (int i = st + 1; i <= st + 2; i ++) {
      ans.pb(mp(i, j));
    }
  }
  for (auto &[x, y] : ans) {
    if (swapped) cout << y << " " << x << "\n";
    else cout << x << " " << y << "\n";
  }
}
void dosth1(int N, int M) {
  bool swapped = false;
  if (N > M) {
    swap(N, M);
    swapped = true;
  }
  vector<pair<int, int>> ans;
  int d = 1 + (N - 1)/2;
  int st = (N - 1)/2;
  for (int i = 1; i <= N; i ++) {
    ans.pb(mp(i, 1));
    ans.pb(mp(i, M));
  }
  for (int j = 1 + d; j <= M - d; j ++) {
    for (int i = st + 1; i <= st + 1; i ++) {
      ans.pb(mp(i, j));
    }
  }
  for (auto &[x, y] : ans) {
    if (swapped) cout << y << " " << x << "\n";
    else cout << x << " " << y << "\n";
  }
}
void Solve(void) {
  int N, M; cin >> N >> M;
  if (N == M) {
    cout << max(1, N + M - 2) << "\n";
    for (int j = 1; j <= M; j ++) {
      cout << 1 << " " << j << "\n";
    }
    for (int j = 2; j < M; j ++) {
      cout << N << " " << j << "\n";
    }
    return;
  }
  if (N % 2 == 0 && M % 2 == 0) {
    cout << N + M - 2 << "\n";
    dosth(N, M);
    return;
  }
  cout << N + M - 1 << "\n";
  if (min(N, M) % 2 == 0) dosth(N, M);
  else dosth1(N, M);
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
