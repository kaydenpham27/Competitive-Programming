#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 1e3 + 10;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

struct Tree{
  int n;
  vector<int64_t>lazy;
  vector<int64_t>st;
  Tree(int _n, int64_t _v): n(_n), st(_n * 4, _v), lazy(_n * 4, _v){};
  void update(int id, int l, int r, int u, int v, int64_t val){
    if (v < l || u > r) return;
    if (u <= l && r <= v) {
      st[id] = val;
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
  int N; cin >> N;
  Tree T(N + 10, 0);
  i64 sum = 0;
  vector<int> v(N, 0);
  for (int i = 1; i < N; i ++) {
    cin >> v[i];
    T.update(1, 1, N - 1, i, i, v[i]);
    sum += v[i];
  }

  auto solveFor = [&]() {
    int l = 1, h = N - 1; while (l <= h) {
      int mid = (l + h)/2;
      if (T.get(1, 1, N, 1, mid) * 2 <= sum) l = mid + 1;
      else h = mid - 1;
    }

    i64 cur = abs(sum - 2 * T.get(1, 1, N, 1, l));
    l --;
    cur = min(cur, abs(sum - 2 * T.get(1, 1, N, 1, l)));
    cout << cur << "\n";
  };

  solveFor();
  int Q; cin >> Q; while (Q --) {
    int id, x; cin >> id >> x;
    sum -= v[id];
    v[id] = x;
    T.update(1, 1, N - 1, id, id, v[id]);
    sum += v[id];
    solveFor();
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
