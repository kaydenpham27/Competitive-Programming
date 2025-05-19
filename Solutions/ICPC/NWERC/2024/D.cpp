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

const int MAXN = 3e5 + 5;
const int MAXW = 6e5 + 10;

int N, f[MAXW][62];
void Solve(void) {
  cin >> N;
  vector<int> p(N);
  int tot = 0;
  for (auto &x : p) {
    cin >> x;
    tot += x;
  }
  sort(all(p));   

  f[0][N] = 1;
  int ans = 0;
  for (int i = N - 1; i >= 0; i --) {
    for (int sum = 0; sum <= 600000; sum ++) {
      if (sum >= p[i]) {
        f[sum][i] += f[sum - p[i]][i + 1];
        if (sum > tot/2 && (sum - p[i] <= tot/2)) {
          ans += f[sum][i];
        }
      }
      f[sum][i] += f[sum][i + 1];
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