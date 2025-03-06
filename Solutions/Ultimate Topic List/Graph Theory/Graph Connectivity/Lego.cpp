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

const int MAXN = 5e5 + 10;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;
struct DSU{
  int N, ccp;
  vector<int> lab, sz;
  vector<int64_t> sum;
  DSU(int _N) : N(_N), ccp(_N), sum(N + 5, 0), sz(_N + 5, 1), lab(_N + 5) {
    for (int i = 1; i <= N; i ++) {
      lab[i] = i;
    }
  }; 
  int findLab(int u) { return (u == lab[u] ? u : lab[u] = findLab(lab[u])); }
  bool unite(int u, int v, int64_t w) {
    int labu = findLab(u);
    int labv = findLab(v);
    if (labu == labv) return false;
    if (sz[labu] < sz[labv]) swap(labu, labv);
    sz[labu] += sz[labv];
    lab[labv] = labu;
    sum[labu] += sum[labv] + w;
    ccp --;
    return true;
  }
};
void Solve(void) {
  int N; cin >> N;
  vector<array<int, 4>> bricks(N + 2);
  vector<int> compress;
  for (int i = 1; i <= N; i ++) {
    for (int j = 0; j < 4; j ++) {
      cin >> bricks[i][j];
      compress.pb(bricks[i][j]);
    }
  }
  sort(all(compress)); compress.erase(unique(all(compress)), compress.end());
  int sz = compress.size();
  vector<vector<array<int, 3>>> ys(sz + 3);  
  for (int i = 1; i <= N; i ++) {
    for (int j = 0; j < 4; j ++) {
      bricks[i][j] = lower_bound(all(compress), bricks[i][j]) - compress.begin() + 1;
    }
    ys[bricks[i][1]].pb({bricks[i][0], bricks[i][2], i});
    ys[bricks[i][3]].pb({bricks[i][0], bricks[i][2], i});
  }

  auto check = [&](int x1, int x2, int xx1, int xx2) {
    if ((xx1 < x2 && x2 < xx2) || (xx1 < x1 && x1 < xx2)) return true;
    return false;
  };

  DSU blocks(N);
  vector<vector<int>> Add(sz + 2), Rem(sz + 2);
  for (int y = 1; y <= sz; y ++) {
    if (!ys[y].empty()) {
      int cnt = 0, par = -1;
      vector<int> xs;
      for (auto [x1, x2, id] : ys[y]) {
        xs.pb(x1);
        xs.pb(x2);
        Add[x1].pb(id);
        Rem[x2].pb(id);
      }
      sort(all(xs)); xs.erase(unique(all(xs)), xs.end());
      for (auto x : xs) {
        // cout << x << " ";
        for (auto id : Rem[x]) {
          cnt --;
          if (cnt == 0) par = -1;
        }
        for (auto id : Add[x]) {
          cnt ++;
          if (cnt == 1) par = id;
          else blocks.unite(id, par, 0);
        }
        Add[x].clear();
        Rem[x].clear();
      }
      // cout << "\n";
    }
  }

  cout << blocks.ccp << "\n";
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
