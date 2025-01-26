#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  int N, X; cin >> N >> X;
  vector<int> a(N);
  for (int i = 0; i < N; i ++) {
    cin >> a[i];
  }
  unordered_map<int, vector<pair<int, int>>> cnt;
  for (int i = 0; i < N; i ++) {
    for (int j = i + 1; j < N; j ++) {
      cnt[a[i] + a[j]].pb(mp(i, j));
    }
  }
  for (int i = 0; i < N; i ++) {
    for (int j = i + 1; j < N; j ++) {
      auto pos = upper_bound(all(cnt[X - a[i] - a[j]]), mp(j, N + 1));
      if (pos != cnt[X - a[i] - a[j]].end()) {
        cout << i + 1 << " " << j + 1 << " " << (*pos).first + 1 << " " << (*pos).second + 1 << "\n";
        return;
      }
    }
  }
  cout << "IMPOSSIBLE";
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}