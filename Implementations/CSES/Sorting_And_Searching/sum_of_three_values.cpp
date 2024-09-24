#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  int N, X; cin >> N >> X;
  vector<int> a(N);
  vector<int> compress;
  for (int i = 0; i < N; i ++) {
    cin >> a[i];
    compress.pb(a[i]);
  }
  sort(all(compress)); compress.erase(unique(all(compress)), compress.end());
  auto getPos = [&](int x) {
    return lower_bound(all(compress), x) - compress.begin();
  };
  vector<vector<int>> pos(N);
  vector<int> cnt(N, 0), b(N, 0);
  for (int i = 0; i < N; i ++) {
    b[i] = getPos(a[i]);
    pos[b[i]].pb(i + 1);
    cnt[b[i]] ++;
  }
  for (int i = 0; i < N; i ++) {
    for (int j = i + 1; j < N; j ++) {
      cnt[b[i]] --;
      cnt[b[j]] --;
      int i3 = getPos(X - a[i] - a[j]);
      if (i3 >= 0 && i3 < N && compress[i3] == X - a[i] - a[j] && cnt[i3] > 0) {
        cout << pos[b[i]].back() << " "; 
        pos[b[i]].pop_back();
        cout << pos[b[j]].back() << " ";
        pos[b[j]].pop_back();
        cout << pos[i3].back() << " ";
        return;
      }
      cnt[b[i]] ++;
      cnt[b[j]] ++;
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