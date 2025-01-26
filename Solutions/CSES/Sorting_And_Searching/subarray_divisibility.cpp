#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  int N; cin >> N;
  vector<int> cnt(N, 0);
  int sum = 0;
  i64 ans = 0;
  cnt[0] ++;
  for (int i = 1; i <= N; i ++) {
    int x; cin >> x;
    sum = ((sum + x) % N + N) % N;
    ans = ans + cnt[sum];
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