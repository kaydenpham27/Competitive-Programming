#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  int N; cin >> N;
  vector<int> pos(N + 1), a(N + 1);
  for (int i = 1; i <= N; i ++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  int ans = 0, curP = N + 1;
  for (int i = 1; i <= N; i ++) {
    if (pos[i] < curP) {
      ans ++;
    }
    curP = pos[i];
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