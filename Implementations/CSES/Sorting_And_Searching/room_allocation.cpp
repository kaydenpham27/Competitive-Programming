#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  int N; cin >> N;
  vector<array<int, 3>> arrives(N);
  for (int i = 0; i < N; i ++) {
    cin >> arrives[i][0] >> arrives[i][1];
    arrives[i][2] = i;
  }
  sort(all(arrives), [&](array<int, 3> &lf, array<int, 3> &rg) {
    return lf[1] < rg[1];
  });
  multiset<pair<int, int>> rooms; 
  vector<int> ans(N);
  int mx = 0;
  for (int i = 0; i < N; i ++) {
    auto pos = rooms.upper_bound(mp(arrives[i][0], -1));
    if (pos != rooms.begin()) {
      pos --;
      ans[arrives[i][2]] = (*pos).second;
      rooms.erase(pos);
      rooms.insert(mp(arrives[i][1], ans[arrives[i][2]]));
    } else {
      ans[arrives[i][2]] = (int)rooms.size() + 1;
      rooms.insert(mp(arrives[i][1], ans[arrives[i][2]]));
    }
    mx = max(mx, (int)rooms.size());
  }
  cout << mx << "\n";
  for (int i = 0; i < N; i ++) cout << ans[i] << " ";
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}