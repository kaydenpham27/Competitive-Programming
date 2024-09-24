#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  unordered_map<i64, int> cnt;
  int N, X; cin >> N >> X;
  i64 ans = 0, sum = 0;
  cnt[0] = 1;
  for (int i = 0; i < N; i ++) {
    int x; cin >> x;
    sum += x;
    ans += cnt[sum - X];
    cnt[sum] ++;
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