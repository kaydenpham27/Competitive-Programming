// FPT UWR
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

const int MAXN = 2e5 + 10;
const int MOD = 998244353;
const i64 INF = INT_MAX/2;

int N, L, R, K, a[MAXN], b[MAXN], low[MAXN], high[MAXN];
void Solve(void) {  
  cin >> N >> L >> R >> K;
  for (int i = 1; i <= N; i ++) cin >> a[i];
  low[N] = L, high[N] = R;
  for (int i = N - 1; i >= 1; i --) {
    if (a[i] > a[i + 1]) {
      low[i] = low[i + 1] + 1;
      high[i] = min(R, high[i + 1] + K);
    } else if (a[i] < a[i + 1]) {
      low[i] = max(L, low[i + 1] - K);
      high[i] = high[i + 1] - 1;
    } else {
      low[i] = low[i + 1]; 
      high[i] = high[i + 1];
    }
    if (low[i] > high[i] || high[i] < L || low[i] > R) {
      cout << -1 << "\n";
      return;
    }
  }
  b[1] = low[1];
  for (int i = 2; i <= N; i ++) {
    if (a[i] > a[i - 1]) {
      b[i] = max(low[i], b[i - 1] + 1);
    } else if (a[i] < a[i - 1]) {
      b[i] = max(low[i], b[i - 1] - K);
    } else {
      b[i] = b[i - 1];
    }
  }
  for (int i = 1; i <= N; i ++) cout << b[i] << " \n"[i == N];
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
