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
  int N, M; cin >> N >> M;
  vector<int> a(N);
  for (int i = 0; i < N; i ++) {
    cin >> a[i];
    a[i] %= M;
    if (a[i] <= M - a[i]) a[i] = -a[i];
    else a[i] = M - a[i];
  }
  sort(all(a));
  int mid = N/2;
  i64 ans = 0;
  for (int i = 0; i < N; i ++) {
    ans += abs(a[mid] - a[i]);
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