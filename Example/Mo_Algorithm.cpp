/*
  Problem: https://codeforces.com/problemset/problem/86/D
  Description: Example for Mo's Alg
  Category: Sqrt Decomposition
*/
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define i128 __int128
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
const int block_size = 447; 
struct Query {
  int l, r, id;
};
void Solve(void) {
  int N, Q; cin >> N >> Q;
  vector<i64> a(N + 1);
  vector<Query> qe;
  for (int i = 1; i <= N; i ++) cin >> a[i];
  for (int i = 1; i <= Q; i ++) {
    int l, r; cin >> l >> r;
    qe.pb({l, r, i});
  }
  sort(all(qe), [&](const Query &lf, const Query &rg) {
    if (lf.l / block_size != rg.l / block_size) return mp(lf.l, lf.r) < mp(rg.l, rg.r);
    return (lf.l / block_size & 1) ? (lf.r < rg.r) : (lf.r > rg.r);
  });

  i64 ans = 0;
  vector<int> cnt(1000006, 0);
  vector<i64> res(Q + 1, 0);
  auto add = [&](int p, int x) {
    ans = ans - 1LL * cnt[a[p]] * cnt[a[p]] * a[p];
    cnt[a[p]] += x;
    ans = ans + 1LL * cnt[a[p]] * cnt[a[p]] * a[p];
  };

  int cur_l = 0, cur_r = -1;
  for (auto [l, r, id] : qe) {
    while (cur_l > l) {
      cur_l --;
      add(cur_l, 1);
    } while (cur_r < r) {
      cur_r ++;
      add(cur_r, 1);
    } while (cur_l < l) {
      add(cur_l, -1);
      cur_l ++;
    } while (cur_r > r) {
      add(cur_r, -1);
      cur_r --;
    }
    res[id] = ans;
  }
  for (int i = 1; i <= Q; i ++) {
    cout << res[i] << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; // cin >> Tests;
  while (Tests --) {
    Solve();
  }
}
