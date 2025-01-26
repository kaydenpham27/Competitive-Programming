// FPT UWR
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define double long double
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 2e5 + 10;
const int MOD = 998244353;
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
    st[id] = min(st[id * 2], st[id * 2 + 1]);
  }
  i64 get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return INT_MAX;
    if (u <= l && r <= v) return st[id];
    push(id);
    int mid = (l + r)/2;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
  }
};
int N, M, Q, a[MAXN], f[MAXN];
void Solve(void) {  
  cin >> N >> M >> Q;
  vector<vector<int>> G(M + 2);
  for (int i = 1; i <= N; i ++) {
    cin >> a[i];
    if (a[i] < a[1]) f[1] ++;
  }
  for (int i = 1; i <= M; i ++) {
    int sz; cin >> sz;
    f[i + 1] = f[i];
    for (int j = 1; j <= sz; j ++) {
      int x; cin >> x; G[i].pb(x);
      if (x > a[1]) f[i + 1] --;
    }
  }
  Tree T(M + 3, 0); 
  for (int i = 1; i <= M + 1; i ++) T.update(1, 1, M + 1, i, i, f[i] - (int)G[i].size());
  while (Q --) {
    int X, Y, Z; cin >> X >> Y >> Z;
    if (G[X][Y - 1] > a[1] && Z < a[1]) T.update(1, 1, M + 1, X + 1, M + 1, 1);
    else if (G[X][Y - 1] < a[1] && Z > a[1]) T.update(1, 1, M + 1, X + 1, M + 1, -1);
    G[X][Y - 1] = Z;
    cout << (T.get(1, 1, M + 1, 1, M + 1) < 0 ? 0 : 1) << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(1);
  int Tests = 1; // cin >> Tests;    
  for (int i = 1; i <= Tests; i ++) {
    // cout << "Case " << i << ": ";
    Solve();    
  }
}
