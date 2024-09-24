#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  int N, K; cin >> N >> K;
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
  int tot = 0;
  for (int i = 0; i < N; i ++) {
    auto pos = rooms.upper_bound(mp(arrives[i][0], INT_MAX));
    if (pos != rooms.begin()) {
      pos --;
      tot ++;
      ans[arrives[i][2]] = (*pos).second;
      rooms.erase(pos);
      rooms.insert(mp(arrives[i][1], ans[arrives[i][2]]));
    } else {
      if ((int)rooms.size() == K) continue;
      tot ++;
      ans[arrives[i][2]] = (int)rooms.size() + 1;
      rooms.insert(mp(arrives[i][1], ans[arrives[i][2]]));
    }
  }
  cout << tot << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}