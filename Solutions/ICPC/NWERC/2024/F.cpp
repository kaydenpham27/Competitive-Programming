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

const int MAXN = 3e5 + 5;
const int MAXW = 1e6;

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
    sz[labv] += sz[labu];
    lab[labu] = labv;
    return true;
  }
};

int N, Q, used[MAXN], l[MAXN], to[MAXN];
void Solve(void) {
  cin >> N >> Q;

  DSU layers(N + 1);

  for (int i = 1; i <= N; i ++) cin >> l[i];
  vector<int> rg; rg.pb(N + 1); l[N + 1] = LLONG_MAX;

  for (int i = N; i >= 1; i --) {
    while (!rg.empty() && l[rg.back()] <= l[i]) rg.pop_back();
    to[i] = rg.back();
    rg.pb(i);

  }

  while (Q --) {
    char q; 
    int L, X;

    cin >> q;
    if (q == '+') {
      cin >> L >> X;
      while (X && (L <= N)) {
        int p = layers.findLab(L);
        if (used[p] + X < l[p]) {
          used[p] += X;
          break;
        } else {
          X -= (l[p] - used[p]);
          used[p] = l[p];
        }

        int nxt = to[p];
        layers.unite(p, nxt, 0);
        L = nxt;
      }
    } else {
      cin >> L;
      cout << used[L] << "\n";
    }
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