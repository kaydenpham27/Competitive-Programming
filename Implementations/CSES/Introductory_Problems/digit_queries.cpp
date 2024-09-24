#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
const i64 mx = 1e18;
i64 countDigitTo(i64 x) {
  i64 sum = 9, digit = 1;
  i64 ans = 0;
  while (true) {
    if (x >= sum) {
      ans = ans + (sum - (sum/10 + 1) + 1) * digit;
      if (ans >= mx) return mx;
      sum = sum * 10 + 9;
      digit ++;
    } else break;
  }
  ans = ans + min(mx, digit * (x - (sum/10 + 1) + 1));
  ans = min(ans, mx);
  return ans;
}
void Solve(void) {
  i64 K; cin >> K;
  i64 l = 1, h = 1e18;
  while (l <= h) {
    i64 mid = (l + h)/2;
    if (countDigitTo(mid) <= K) l = mid + 1;
    else h = mid - 1;
  }
  string s = to_string(l - 1) + to_string(l);
  i64 cnt = countDigitTo(l);
  cnt = cnt - K;
  while (cnt--) {
    s.pop_back();
  }
  cout << s.back() << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}