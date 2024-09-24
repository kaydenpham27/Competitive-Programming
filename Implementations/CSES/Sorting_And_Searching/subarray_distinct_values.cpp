#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  int N, K; cin >> N >> K;
  unordered_map<int, int> cnt;
  int prev = 1, tot = 0;
  i64 ans = 0;
  vector<int> a(N + 1);
  for (int i = 1; i <= N; i ++) {
    cin >> a[i];
    cnt[a[i]] ++;
    if (cnt[a[i]] == 1) tot ++;
    while (tot > K) {
      cnt[a[prev]] --;
      if (cnt[a[prev]] == 0) tot --;
      prev ++;
    }
    ans = ans + i - prev + 1;
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