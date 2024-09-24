#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  int N, X; cin >> N >> X;
  vector<int> a(N + 1);
  vector<i64> compress;
  compress.pb(0);
  i64 sum = 0;
  for (int i = 1; i <= N; i ++) {
    cin >> a[i];
    sum += a[i];
    compress.pb(sum);
    compress.pb(sum - X);
  }
  sort(all(compress)); compress.erase(unique(all(compress)), compress.end());
  vector<int> cnt(3 * N);
  auto getPos = [&](i64 x) {
    return lower_bound(all(compress), x) - compress.begin();
  };
 
  cnt[getPos(0)] ++;
  sum = 0;
  i64 ans = 0;
  for (int i = 1; i <= N; i ++) {
    sum += a[i];
    ans += cnt[getPos(sum - X)];
    cnt[getPos(sum)] ++;
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