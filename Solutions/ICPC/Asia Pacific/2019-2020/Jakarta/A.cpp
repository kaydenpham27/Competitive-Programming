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

const int MAXN = 2e5 + 10;
const int MOD = 235813;
const i64 INF = INT_MAX/2;

int N, a[MAXN];
void Solve(void) {  
  cin >> N;
  for (int i = 1; i <= N; i ++) cin >> a[i];
  for (int i = 1, j = 2; i <= N; i ++) {
    if (a[i] == 1) cout << N << " ";
    else if (a[i] == N) cout << 1 << " ";
    else cout << j++ << " ";
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