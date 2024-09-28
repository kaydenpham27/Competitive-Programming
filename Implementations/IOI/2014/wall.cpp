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
struct DataTree {
  const i64 INF = 1e18;
  struct Data {
    i64 mn = 0, mx = LLONG_MAX;
  };
  vector<Data> st;
  DataTree (int _N) : st(4 * _N + 4) {};
  void Apply(int id, i64 mn, i64 mx) {
    st[id].mn = max(st[id].mn, mn);
    st[id].mx = max(st[id].mx, st[id].mn);
    st[id].mx = min(st[id].mx, mx);
    st[id].mn = min(st[id].mn, st[id].mx);
  }
  void push(int id, int l, int r) {
    Apply(id * 2, st[id].mn, st[id].mx);
    Apply(id * 2 + 1, st[id].mn, st[id].mx);
    st[id].mn = 0; st[id].mx = LLONG_MAX;
  }
  void update(int id, int l, int r, int u, int v, i64 mn, i64 mx) {
    if (v < l || u > r) return;
    if (u <= l && r <= v) {
      Apply(id, mn, mx);
      return;
    }
    push(id, l, r);
    int mid = (l + r)/2;
    update(id * 2, l, mid, u, v, mn, mx);
    update(id * 2 + 1, mid + 1, r, u, v, mn, mx);
  }
  Data get(int id, int l, int r, int p) {
    if (l == r) return st[id];
    push(id, l, r);
    int mid = (l + r)/2;
    if (p <= mid) return get(id * 2, l, mid, p);
    return get(id * 2 + 1, mid + 1, r, p);
  }
};
void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]) {
  DataTree T(n + 2);
  for (int i = 0; i < k; i ++) {
    if (op[i] == 1) T.update(1, 1, n, left[i] + 1, right[i] + 1, height[i], LLONG_MAX);
    else T.update(1, 1, n, left[i] + 1, right[i] + 1, 0, height[i]);
  }
  for (int i = 0; i < n; i ++) {
    finalHeight[i] = T.get(1, 1, n, i + 1).mn;
  }
}
/*------------------------ Submit from this line up only ------------------------------- */
void Solve(void) {  
  // Local tests
  int op[] = {1, 2, 2, 1, 1, 2};
  int left[] = {1, 4, 3, 0, 2, 6};
  int right[] = {8, 9, 6, 5, 2, 7};
  int height[] = {4, 1, 5, 3, 5, 0};
  int finalHeight[10];
  buildWall(10, 6, op, left, right, height, finalHeight);
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}