// FPTU UWR
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define int long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 3e5 + 10;
const int MOD = 235813;
const i64 INF = INT_MAX/2;

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
    push(id);
    int mid = (l + r)/2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
  }
};

int N, M, c[MAXN], m[MAXN]; vector<int> G[MAXN], compress, sortedC;
int getPos(int x) {
  return lower_bound(all(compress), x) - compress.begin() + 1;
}
void Solve(void) {  
  cin >> N >> M;
  for (int i = 1; i <= N; i ++) {
    cin >> c[i];
    compress.pb(c[i]);
  }
  for (int i = 1; i <= M; i ++) {
    cin >> m[i];
    for (int j = 1; j <= m[i]; j ++) {
      int x; cin >> x;
      G[i].pb(x);
      compress.pb(x);
    }
  }
  sort(all(compress)); compress.erase(unique(all(compress)), compress.end());
  int sz = compress.size();
  Tree TC(sz + 6, 0), TCC(sz + 6, 0);
  for (int i = 1; i <= N; i ++) {
    c[i] = getPos(c[i]);
    sortedC.pb(c[i]);
    TC.update(1, 1, sz, c[i], c[i], 1);
  }
  int invC = 0;
  for (int i = 1; i <= N; i ++) {
    TC.update(1, 1, sz, c[i], c[i], -1);
    invC += TC.get(1, 1, sz, 1, c[i] - 1);
  }
  for (int i = 1; i <= M; i ++) {
    for (auto &x : G[i]) {
      x = getPos(x);
    }
  }
  // cout << invC << "\n";
  sort(all(sortedC));
  for (int i = 1; i <= M; i ++) {
    i64 ans = LLONG_MAX;
    i64 curI = 0;
    for (auto x : G[i]) {
      TCC.update(1, 1, sz, x, x, 1);
      int p = upper_bound(all(sortedC), x) - sortedC.begin();
      curI += N - p;      
    }
    for (auto x : G[i]) {
      TCC.update(1, 1, sz, x, x, -1);
      curI += TCC.get(1, 1, sz, 1, x - 1);
    }
    ans = min(ans, curI);
    // cout << curI << "\n";
    for (auto x : G[i]) {
      int p = upper_bound(all(sortedC), x) - sortedC.begin();
      curI -= (N - p);
      int pL = lower_bound(all(sortedC), x) - sortedC.begin() - 1;
      curI += pL + 1;
      ans = min(ans, curI);      
      // cout << x << " " << curI << "\n";
    }
    cout << ans + invC << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; // cin >> Tests;    
  for (int i = 1; i <= Tests; i ++) {
    // cout << "Case " << i << ": ";
    Solve();    
  }
}
