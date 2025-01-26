#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  int N, T; cin >> N >> T;
  vector<int> a(N);
  for (int &x : a) cin >> x;
  i64 mx = 1e18;
  auto solve = [&](i64 tot) {
    i64 ans = 0;
    for (auto x : a) {
      ans = ans + tot/x;
      if (ans >= mx) return mx;
    }
    return ans;
  };
 
  i64 l = 1, h = 1e18;
  while (l <= h) {
    i64 mid = (l + h)/2;
    if (solve(mid) < T) l = mid + 1;
    else h = mid - 1;
  }
  cout << l;
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}