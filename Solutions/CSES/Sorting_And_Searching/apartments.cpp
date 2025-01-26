#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  int N, M, K; cin >> N >> M >> K;
  vector<int> a(N), b(M);
  for (int i = 0; i < N; i ++) cin >> a[i];
  for (int i = 0; i < M; i ++) cin >> b[i];
  sort(all(a)); sort(all(b));
  int i = 0, j = 0;
  int ans = 0;
  while (i < N && j < M) {
    if (a[i] - K > b[j]) j ++;
    else {
      if (a[i] + K >= b[j]) {
        ans ++;
        i ++; j ++;
      } else {
        i ++;
      }
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