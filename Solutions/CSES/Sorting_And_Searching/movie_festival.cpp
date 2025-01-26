#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  int N; cin >> N;
  vector<pair<int, int>> v(N);
  for (int i = 0; i < N; i ++) {
    cin >> v[i].second >> v[i].first;
  }
  sort(all(v));
  int mn = -1, ans = 0;
  for (int i = 0; i < N; i ++) {
    if (mn <= v[i].second) {
      mn = v[i].first;
      ans ++;
    }
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