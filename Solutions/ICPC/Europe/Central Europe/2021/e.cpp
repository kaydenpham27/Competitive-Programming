#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()  

const int MAXN = 3e5 + 10;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;
struct Data {
  i64 sum, pref, suff, best;
  Data(i64 x = 0) {
    sum = x;
    pref = max(0LL, x);
    suff = max(0LL, x);
    best = max(0LL, x);   
  }

  static Data Merge(Data lf, Data rg) {
    Data res(0);
    res.sum = lf.sum + rg.sum;
    res.pref = max(lf.pref, lf.sum + rg.pref);
    res.suff = max(rg.suff, rg.sum + lf.suff);
    res.best = max({lf.best, rg.best, res.sum, res.pref, res.suff, lf.suff + rg.pref});
    return res;
  }
};
struct PST {

  struct Node {
    Node *l, *r;
    Data v;
    Node(i64 x) {
      v = Data(x);
      l = nullptr;
      r = nullptr;
    }

    Node(Node *lf, Node *rg) {
      l = lf; 
      r = rg;
      
      v = Data::Merge(lf->v, rg->v);
    }
  };

  Node* snap[MAXN + 10];

  // Build the first copy
  Node* build(int l, int r) {
    if (l == r) return new Node(0);
    int mid = (l + r)/2;
    return new Node(build(l, mid), build(mid + 1, r));
  }

  Node* update(Node *node, int l, int r, int p, i64 x) {
    if (l == r) return new Node(x);
    int mid = (l + r)/2;
    if (p <= mid) return new Node(update(node->l, l, mid, p, x), node->r);
    return new Node(node->l, update(node->r, mid + 1, r, p, x));
  }

  // Be careful, don't create new node every time we query something
  Data getBest(Node *node, int l, int r, int u, int v) {
    if (v < l || u > r || node == nullptr) return Data(0);
    if (u <= l && r <= v) {
      return node->v;
    }
    int mid = (l + r)/2;
    return Data::Merge(getBest(node->l, l, mid, u, v), getBest(node->r, mid + 1, r, u, v));
  }

  Data getBestTime(int time, int l, int r, int u, int v) {
    return getBest(snap[time], l, r, u, v);
  }

  void updateTime(int time, int l, int r, int p, i64 x) {
    snap[time] = update(snap[time], l, r, p, x);
  }
};

void Solve(void) {
  int N, M; cin >> N >> M;
  int K; cin >> K;
  vector<vector<pair<int, int>>> rs(N + 2);
  for (int i = 1; i <= K; i ++) {
    int x, y, v; cin >> x >> y >> v;
    rs[x].pb(mp(y, v));
  }


  PST grid;
  grid.snap[0] = grid.build(1, M);
  for (int r = 1; r <= N; r ++) {
    grid.snap[r] = grid.snap[r - 1];
    for (auto [c, v] : rs[r]) {
      Data node = grid.getBest(grid.snap[r], 1, M, c, c);
      grid.snap[r] = grid.update(grid.snap[r], 1, M, c, node.sum + v);
    }
  }

  int Q; cin >> Q; 
  vector<i64> ans(Q + 1, 0);
  for (int i = 1; i <= Q; i ++) {
    i64 H, X, Y; cin >> H >> X >> Y;
    H = (H ^ ans[max(i - 3, 0)]);
    X = (X ^ ans[max(i - 2, 0)]);
    Y = (Y ^ ans[max(i - 1, 0)]);

    ans[i] = max(0LL, grid.getBestTime(H, 1, M, X, Y).best);
    cout << ans[i] << "\n";

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