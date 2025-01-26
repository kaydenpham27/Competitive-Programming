#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  int N; cin >> N;
  vector<pair<int, int>> v(N);
  for (auto &[t, d] : v) cin >> t >> d;
  sort(all(v));
  i64 ans = 0;
  i64 curT = 0;
  for (auto [t, d] : v) {
    curT += t;
    ans = ans + d - curT;
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}