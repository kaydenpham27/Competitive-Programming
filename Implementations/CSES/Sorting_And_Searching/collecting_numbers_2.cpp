#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  int N, Q; cin >> N >> Q;
  vector<int> pos(N + 2, 0);
  vector<int> a(N + 1);
  for (int i = 1; i <= N; i ++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  pos[0] = N + 1;
  pos[N + 1] = N + 1;
  int ans = 0;
  for (int i = 1; i <= N; i ++) {
    ans += pos[i] < pos[i - 1];
  }
  // cout << ans << "\n";
  while (Q --) {
    int i, j; cin >> i >> j;
    if (a[i] > a[j]) swap(i, j);
    int v1 = a[i], v2 = a[j];
    if (pos[v1] < pos[v1 - 1]) ans --;
    if (v2 - 1 != v1 && pos[v2] < pos[v2 - 1]) ans --;
 
    if (pos[v1 + 1] < pos[v1]) ans --;
    if (pos[v2 + 1] < pos[v2]) ans --;
 
    swap(pos[v1], pos[v2]);
    swap(a[i], a[j]);
    if (pos[v1] < pos[v1 - 1]) ans ++;
    if (v2 - 1 != v1 && pos[v2] < pos[v2 - 1]) ans ++;
 
    if (pos[v1 + 1] < pos[v1]) ans ++;
    if (pos[v2 + 1] < pos[v2]) ans ++;
 
    cout << ans << "\n";
  }
} 
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}