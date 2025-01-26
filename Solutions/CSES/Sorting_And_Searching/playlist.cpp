#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  int N; cin >> N;
  vector<int> a(N + 1), prev(N + 1, 0);
  vector<int> compress;
  for (int i = 1; i <= N; i ++) {
    cin >> a[i];
    compress.pb(a[i]);
  }
  sort(all(compress)); compress.erase(unique(all(compress)), compress.end());
  int j = 1, ans = 0;
  for (int i = 1; i <= N; i ++) {
    int p = lower_bound(all(compress), a[i]) - compress.begin();
    while (j <= prev[p]) {
      j ++;
    }
    ans = max(ans, i - j + 1);
    prev[p] = i;
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