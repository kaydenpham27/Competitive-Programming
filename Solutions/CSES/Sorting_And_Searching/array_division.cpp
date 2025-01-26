#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  int N, K; cin >> N >> K;
  vector<int> a(N + 1);
  for (int i = 1; i <= N; i ++) cin >> a[i];
 
  auto check = [&](i64 x) {
    i64 sum = 0; int grp = 1;
    for (int i = 1; i <= N; i ++) {
      if (a[i] > x) return false;
      if (sum + a[i] > x) {
        sum = a[i];
        grp ++;
      } else {
        sum += a[i];
      }
    }
    return grp <= K;
  };
 
  i64 l = 1, h = 1e18;
  while (l <= h) {
    i64 mid = (l + h)/2;
    if (check(mid)) h = mid - 1;
    else l = mid + 1;
  }
  cout << l << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}