// FPT UWR
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define double long double
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 2e5 + 10;
const int MOD = 998244353;
const i64 INF = INT_MAX/2;

int N;
void Solve(void) {  
  cin >> N;
  vector<pair<double, double>> lands(N);
  for (auto &[a, b] : lands) {
    cin >> a >> b;
    if (a > b) swap(a, b);
  }
  sort(all(lands), greater<pair<double, double>>());
  double ans = 0, mxB = 0;
  for (int i = 0; i < N; i ++) {
    auto [a, b] = lands[i];
    ans = max(ans, a * b / 2);
    if (i != 0) ans = max(ans, a * min(b, mxB));
    mxB = max(mxB, b);
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(1);
  int Tests = 1; // cin >> Tests;    
  for (int i = 1; i <= Tests; i ++) {
    // cout << "Case " << i << ": ";
    Solve();    
  }
}
