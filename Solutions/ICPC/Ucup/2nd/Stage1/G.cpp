// FPTU UWR
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 1e5 + 5;
const int MAXW = 1e6;
const int BLOCK_SIZE = 320;

struct Tree{
  int n;
  vector<int64_t>st;
  Tree(int _n, int64_t _v): n(_n), st(_n * 4, _v) {};
  void update(int id, int l, int r, int u, int v, int64_t val){
    if (v < l || u > r) return;
    if (u <= l && r <= v) {
      st[id] += val;
      return;
    }
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
};
void Solve(void) {
  int N;
  cin >> N;
  Tree T(N + 10, 0);
  vector<i64> a(N + 5), p(N + 5);
  for (int i = 1; i <= N; i ++) cin >> a[i];
  for (int i = 1; i <= N; i ++) cin >> p[i];
  
  int numBlock = (N + BLOCK_SIZE - 1)/BLOCK_SIZE;

  vector<pair<int, int>> blockRange(numBlock + 5, mp(0, 0));
  vector<vector<int>> sa(numBlock + 4);
  for (int i = 1; i <= numBlock; i ++) {
    blockRange[i] = mp(BLOCK_SIZE * (i - 1) + 1, min(N, BLOCK_SIZE * i));
    for (int j = blockRange[i].first; j <= blockRange[i].second; j ++) {
      sa[i].pb(a[j]);
    }
    sort(all(sa[i]));
  }
  // [L, r]
  vector<vector<i64>> f(numBlock + 5, vector<i64> (N + 5, 0));
  // [l, R]
  vector<vector<i64>> g(N + 5, vector<i64> (numBlock + 5, 0));

  for (int lid = numBlock; lid >= 1; lid --) {
    for (int r = blockRange[lid].first; r <= blockRange[lid].second; r ++) {
      f[lid][r] = f[lid][r - 1] + T.get(1, 1, N, a[r] + 1, N);
      T.update(1, 1, N, a[r], a[r], 1);
    }
    for (int r = blockRange[lid].first; r <= blockRange[lid].second; r ++) {
      T.update(1, 1, N, a[r], a[r], -1);
    }
    for (int r = blockRange[lid].second + 1; r <= N; r ++) {
      f[lid][r] = f[lid][r - 1] + f[lid + 1][r] - f[lid + 1][r - 1];
      int p = upper_bound(all(sa[lid]), a[r]) - sa[lid].begin();
      f[lid][r] += (int)sa[lid].size() - p;
    }
  }

  for (int rid = 1; rid <= numBlock; rid ++) {
    for (int l = blockRange[rid].second; l >= blockRange[rid].first; l --) {
      g[l][rid] = g[l + 1][rid] + T.get(1, 1, N, 1, a[l] - 1);
      T.update(1, 1, N, a[l], a[l], 1);
    }
    for (int l = blockRange[rid].second; l >= blockRange[rid].first; l --) {
      T.update(1, 1, N, a[l], a[l], -1);
    }
    for (int l = blockRange[rid].first - 1; l >= 1; l --) {
      g[l][rid] = g[l + 1][rid] + g[l][rid - 1] - g[l + 1][rid - 1];
      int p = lower_bound(all(sa[rid]), a[l]) - sa[rid].begin() - 1;
      g[l][rid] += p + 1;
    }
  }

  auto calc = [&](int l, int r) {
    int L = -1, R = -1;
    i64 ans = 0;
    for (int i = 1; i <= numBlock; i ++) {
      if (blockRange[i].first >= l && L == -1) {
        L = i;
      } if (blockRange[i].second <= r) {
        R = i;
      }
    }
    if (r - l + 1 <= BLOCK_SIZE) {
      for (int i = l; i <= r; i ++) {
        ans += T.get(1, 1, N, a[i] + 1, N);
        T.update(1, 1, N, a[i], a[i], 1);
      }
      for (int i = l; i <= r; i ++) {
        T.update(1, 1, N, a[i], a[i], -1);
      }
    } else {
      ans = ans + f[L][r] + g[l][R] - f[L][blockRange[R].second];
      for (int i = l; i <= blockRange[L].first - 1; i ++) {
        T.update(1, 1, N, a[i], a[i], 1);
      }
      for (int i = blockRange[R].second + 1; i <= r; i ++) {
        ans += T.get(1, 1, N, a[i] + 1, N);
      }
      for (int i = l; i <= blockRange[L].first - 1; i ++) {
        T.update(1, 1, N, a[i], a[i], -1);
      }
    }
    return ans;
  };

  // cout << calc(8, 8) << "\n";

  multiset<i64> best; set<pair<int, int>> s;
  best.insert(f[1][N]);
  s.insert(mp(1, N));
  for (int i = 1; i <= N; i ++) {
    i64 ans = (*best.rbegin());
    p[i] = (p[i] ^ ans);


    cout << ans << " \n"[i == N];
    auto it = s.upper_bound(mp(p[i], N + 1)); it --;
    auto [L, R] = (*it);

    // cout << "POS " << i << " " << p[i] << " " << ans << "\n";
    // cout << "Size " << (int)s.size() << "\n";
    // for (auto p : s) {
    //   cout << p.first << " " << p.second << " " << calc(p.first, p.second) << "\n";
    // }
    // cout << "\n";



    best.erase(best.find(calc(L, R)));
    s.erase(it);

    if (L < p[i]) {
      best.insert(calc(L, p[i] - 1));
      s.insert(mp(L, p[i] - 1));
    }
    if (p[i] < R) {
      best.insert(calc(p[i] + 1, R));
      s.insert(mp(p[i] + 1, R));
    }
  }
}
signed main() {
  // ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; cin >> Tests;    
  for (int i = 1; i <= Tests; i ++) {
    // cout << "Case " << i << ": ";
    Solve();    
  }
}