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

int f[10][2][2];
int dp(int p, bool smaller, bool started) {
  if (p == 9) {
    return started;
  }
  if (f[p][smaller][started] != -1) return f[p][smaller][started];
  int &ans = f[p][smaller][started] = 0;
}
int calc(int x) {
  memset(f, -1, sizeof(f));
  return dp(0, false, false);
}
void Solve(void) {
  int N; cin >> N;
  int L = 1, H = 999999999; while (L <= H) {
    int mid = (L + H)/2;
    if (calc(mid) >= N) H = mid - 1;
    else L = mid + 1;
  }
  cout << L << "\n";
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
