#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
int N, D;
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
      st[id] = val;
      lazy[id] = val;
      return;
    }
    // push(id);
    int mid = (l + r)/2;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
  }
  int find(int id, int l, int r, int u, int v, int x){
    if (v < l || u > r) return N + 1;
    if (st[id] <= x) return N + 1;
    if (l == r) return l;
    // push(id);
    int mid = (l + r)/2;
    int lf = find(id * 2, l, mid, u, v, x);
    if (lf != N + 1) return lf;
    return find(id * 2 + 1, mid + 1, r, u, v, x);
  }
  int get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r)/2;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
  }
};
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> N >> D;
  vector<int> a(N + 1), opt(N + 1);
  vector<pair<int, int>> reorder;
  for (int i = 1; i <= N; i ++) {
    cin >> a[i];
    reorder.pb(mp(a[i], i));
  }
  multiset<int> ms;
  Tree R(N + 1, 0);
  /// min value in range [i - D, i];
  for (int i = 1; i <= N; i ++) {
    ms.insert(a[i]);
    int mn = (*ms.begin());
    R.update(1, 1, N, i, i, mn);
    if (i >= D) {
      ms.erase(ms.find(a[i - D + 1]));
    }
  }
  /// Find farest to the right that does not have D + 1 consecutive values > a[i]
  for (int i = N; i >= 1; i --) opt[i] = R.find(1, 1, N, i + D, N, a[i]);
  sort(all(reorder), [&](pair<int, int> &a, pair<int, int> &b){
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
  });
  Tree T(N + 3, 0); 
  int ans = 0;
  /// f[i] = max(f[j in (i + 1 .. opt[pos])] + 1) where a[j] > a[i] 
  for (auto [x, pos] : reorder) {
    int best = T.get(1, 1, N, pos + 1, opt[pos]) + 1;
    T.update(1, 1, N, pos, pos, best);
    ans = max(ans, best);
  }
  cout << ans << "\n";
}
