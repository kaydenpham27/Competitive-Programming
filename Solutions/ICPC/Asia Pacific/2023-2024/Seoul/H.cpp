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

const int MAXN = 2e5 + 5;
const int MAXW = 50000;

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

int N, a[2][MAXN];
void Solve(void) {
  cin >> N;
  for (int i = 1; i <= 2; i ++) {
    for (int j = 1; j <= N; j ++) {
      cin >> a[i][j];
    }
  }

  Tree T(MAXW + 10, 0);

  int add = 0, ans = 0;
  vector<pair<int, int>> v;
  int sum = 0, cnt = 0;
  for (int j = 1; j <= N; j ++) {
    if (a[1][j] == a[2][j]) {
      add += a[1][j];
      cnt ++;
    } 
    sum += a[1][j];
    v.pb(mp(a[1][j], a[2][j]));
  }
  sort(all(v));

  for (auto [a, b] : v) {
    if (a == b) {
      ans = max(ans, sum + add + T.get(1, 1, MAXW, b + 1, MAXW));
    } else {
      
    }
  }

  cout << ans + add << "\n";
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