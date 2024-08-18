#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
const int block_size = 450;
void Solve(void) {
  int N, Q; cin >> N >> Q;
  vector<int> f(N + 2, 0);
  vector<vector<int>> sum(block_size + 3, vector<int> (block_size + 3, 0));
  vector<vector<pair<int, int>>> st(N + 2);
  vector<vector<int>> en(N + 2);
  for (int i = 0; i < Q; i ++) {
    int a, l, d; cin >> a >> l >> d;
    st[a].pb(mp(l, d));
    if (d < block_size) en[a + (l - 1) * d].pb(d);
  }
  for (int i = 1; i <= N; i ++) {
    for (auto [l, d] : st[i]) {
      if (d >= block_size) {
        for (int j = i; j <= i + (l - 1) * d; j += d) f[j] ++;
      } else {
        sum[i % d][d] ++;
      }
    }
    for (int j = 1; j < block_size; j ++) {
      f[i] += sum[i % j][j];
    }
    for (auto d : en[i]) {
      sum[i % d][d] --;
    }
  }
  for (int i = 1; i <= N; i ++) cout << f[i] << " \n"[i == N];
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}
