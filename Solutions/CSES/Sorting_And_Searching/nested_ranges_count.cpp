#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
struct Tree{
  int n;
  vector<int64_t>lazy;
  vector<int64_t>st;
  Tree(int _n, int64_t _v): n(_n), st(_n * 4, _v), lazy(_n * 4, _v){};
  void push(int id){
    int64_t add = lazy[id];
    lazy[id * 2] += add, st[id * 2] += add;
    lazy[id * 2 + 1] += add, st[id * 2 + 1] += add;
    lazy[id] = 0;
  }
  void update(int id, int l, int r, int u, int v, int64_t val){
    if (v < l || u > r) return;
    if (u <= l && r <= v) {
      st[id] += val;
      lazy[id] += val;
      return;
    }
    push(id);
    int mid = (l + r)/2;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    st[id] = st[id * 2] + st[id * 2 + 1];
  }
  i64 get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r)/2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
  }
  int find(int id, int l, int r, int u, int v){
    if (v < l || u > r) return 0;
    if (st[id] > 0) return 0;
    if (l == r) return l;
    push(id);
    int mid = (l + r)/2;
    int rg = find(id * 2 + 1, mid + 1, r, u, v);
    if (rg != 0) return rg;
    return find(id * 2, l, mid, u, v);
  }
};
void Solve(void) {
  int N; cin >> N;
  vector<array<int, 3>> v(N);
  vector<int> compress;
  Tree T(2 * N + 2, 0);
  for (int i = 0; i < N; i ++) {
    cin >> v[i][0] >> v[i][1];
    v[i][2] = i;
    compress.pb(v[i][0]);
    compress.pb(v[i][1]);
  }
  sort(all(compress)); compress.erase(unique(all(compress)), compress.end());
  for (int i = 0; i < N; i ++) {
    v[i][0] = lower_bound(all(compress), v[i][0]) - compress.begin() + 1;
    v[i][1] = lower_bound(all(compress), v[i][1]) - compress.begin() + 1;
  }
  sort(all(v), [&](const array<int, 3> &lf, const array<int, 3> &rg) {
    if (lf[0] != rg[0]) return lf[0] < rg[0];
    return lf[1] > rg[1];
  });
  vector<i64> contained(N, 0), contains(N, 0);
  int mx = 0;
  for (int i = 0; i < N; i ++) {
    int id = v[i][2];
    if (v[i][1] <= mx) {
      contained[id] += T.get(1, 1, 2 * N, v[i][1], 2 * N);
    }
    // cout << contained[id] << "\n";
    mx = max(mx, v[i][1]);
    T.update(1, 1, 2 * N, v[i][1], v[i][1], 1);
  }
  for (int i = 0; i < N; i ++) {
    T.update(1, 1, 2 * N, v[i][1], v[i][1], -1);
  }
  int mn = INT_MAX;
  for (int i = N - 1; i >= 0; i --) {
    int id = v[i][2];
    if (v[i][1] >= mn) {
      contains[id] += T.get(1, 1, 2 * N, 1, v[i][1]);
    }
    mn = min(mn, v[i][1]);
    T.update(1, 1, 2 * N, v[i][1], v[i][1], 1);
  }
  for (int i = 0; i < N; i ++) cout << contains[i] << " \n"[i == N - 1];
  for (int i = 0; i < N; i ++) cout << contained[i] << " \n"[i == N - 1];
} 
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}