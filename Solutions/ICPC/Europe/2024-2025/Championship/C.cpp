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

const int MAXN = 100;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

void Solve(void) {
  int N, K; cin >> N >> K;
  multiset<int> ms, mss;
  for (int i = 0; i < N; i ++) {
    int x; cin >> x; 
    if (x < K) ms.insert(x);
    else mss.insert(x);
  }
  int ans = 0;
  while ((int)ms.size() >= 2) {
    int cur = (*ms.rbegin());
    ms.erase(ms.find(cur));

    auto se = ms.upper_bound(K - cur - 1);
    if (se != ms.begin()) {
      se --;
      ms.erase(se);
    }
    if (!mss.empty()) {
      auto it = mss.end(); it --;
      mss.erase(it);
      if (mss.empty() & ms.empty()) {
        // Do nothing
      } else {
        ans ++;
      }
    } else {
      if ((int)ms.size() >= 2) {
        auto it = ms.end(); it --;
        ms.erase(it);
        ans ++;
      } else {
        break;
      }
    }
  }
  ans += max(0LL, (int)mss.size() - 1);
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
