// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
 
using namespace std;
 
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MAXN = 2e5 + 10;
const int INF = 1e9;
int N, Q, a[MAXN];
struct DataTree {
  const i64 INF = 1e18;
  struct Data {
    i64 sum, mn, lz;
  };
  vector<Data> st;
  DataTree (int _N) : st(4 * _N + 4) {}
  Data combine(Data lf, Data rg) {
    Data res;
    res.mn = min(lf.mn, rg.mn);
    res.sum = lf.sum + rg.sum;  
    res.lz = 0;
    return res;
  }
  void push(int id, int l, int r) {
    i64 &add = st[id].lz;
    st[id * 2].mn += add; st[id * 2 + 1].mn += add;
    st[id * 2].lz += add; st[id * 2 + 1].lz += add;
    int mid = (l + r)/2;
    st[id * 2].sum += add * (mid - l + 1);
    st[id * 2 + 1].sum += add * (r - mid);
    add = 0;
  }
  void build(int id, int l, int r) {
    if (l == r) {
      st[id].sum = st[id].mn = a[l];
      return;
    }
    int mid = (l + r)/2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = combine(st[id * 2], st[id * 2 + 1]);
  }
  void update(int id, int l, int r, int u, int v, i64 x) {
    if (v < l || u > r) return;
    if (u <= l && r <= v) {
      st[id].sum += x * (r - l + 1);
      st[id].mn += x;
      st[id].lz += x;
      return;
    }
    push(id, l, r);
    int mid = (l + r)/2;
    update(id * 2, l, mid, u, v, x);
    update(id * 2 + 1, mid + 1, r, u, v, x);
    st[id] = combine(st[id * 2], st[id * 2 + 1]);
  }
  Data get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return {0, LLONG_MAX, 0};
    if (u <= l && r <= v) return st[id];
    push(id, l, r);
    int mid = (l + r)/2;
    return combine(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
  }
};
void Solve(void) {  
  cin >> N >> Q;
  for (int i = 1; i <= N; i ++) cin >> a[i];
  DataTree T(N + 2); T.build(1, 1, N);
  while (Q --) {
    char op; int A, B, C; cin >> op >> A >> B;
    if (op == 'M') {
      cout << T.get(1, 1, N, A, B).mn << "\n";
    } else if (op == 'S') {
      cout << T.get(1, 1, N, A, B).sum << "\n";
    } else {
      cin >> C;
      T.update(1, 1, N, A, B, C);
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  freopen("haybales.in", "r", stdin);
  freopen("haybales.out", "w", stdout);
  cout << fixed << setprecision(10);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}