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

const int MAXN = 1e5 + 5;
const int MAXW = 1e6;

int N, a[MAXN];
void Solve(void) {
  cin >> N;
  vector<int> cnt(31, 0);
  for (int i = 1; i <= N; i ++) cin >> a[i];
  for (int i = 1; i <= N; i ++) {
    for (int b = 29; b >= 0; b --) {
      if (a[i] >> b & 1) {
        cnt[b] ++;
        break;
      }
    }
  }
  for (int b = 0; b < 30; b ++) {
    cnt[0] = max(cnt[0], cnt[b]);
  }
  cout << cnt[0] << "\n";
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