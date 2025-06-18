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
const int MAXW = 1e6;

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

void Maximize(pair<int, int> &a, pair<int, int> b) {
  if (a.first < b.first) a = b;
  else if (a.first == b.first) a.second = min(a.second, b.second);
}

int N, K;
void Solve(void) {
  cin >> N >> K;
  Tree T(2 * MAXW + 10, 0);
  vector<pair<int, int>> p(N);
  vector<vector<int>> add(2 * MAXW + 10), rmv(2 * MAXW + 10);
  for (int i = 0; i < N; i ++) {
    cin >> p[i].first >> p[i].second;
    p[i].first += MAXW;
    p[i].second += MAXW;
    T.update(1, 0, 2 * MAXW, p[i].first, p[i].second, 1);
    add[p[i].second].pb(i);
    rmv[p[i].first].pb(i);
  }

  set<int> cid;
  vector<int> biggest(N + 2, -1), smallest(N + 2, N);

  sort(all(p), [&](pair<int, int> &p, pair<int, int> &q) {
    if (p.second != q.second) return p.second < q.second;
    return p.first < q.first;
  });

  for (int i = 0; i <= 2 * MAXW; i ++) {
    for (auto x : rmv[i]) {
      cid.insert(x);
    }
    for (auto x : add[i]) {
      biggest[x] = max(biggest[x], (*cid.rbegin()));
      smallest[x] = min(smallest[x], (*cid.begin()));
    }
    for (auto x : add[i]) {
      cid.erase(x);
    }
  }

  for (int i = 2 * MAXW; i >= 0; i --) {
    for (auto x : add[i]) {
      cid.insert(x);
    }
    for (auto x : rmv[i]) {
      biggest[x] = max(biggest[x], (*cid.rbegin()));
      smallest[x] = min(smallest[x], (*cid.begin()));
    }
    for (auto x : rmv[i]) {
      cid.erase(x);
    }
  }

  for (int i = 0; i < N; i ++) cout << p[i].first - MAXW << " " << p[i].second - MAXW << "\n";
  for (int i = 0; i < N; i ++) {
    cout << smallest[i] << " " << biggest[i] << "\n";
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