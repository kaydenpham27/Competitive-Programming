#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define ld long double
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 1e3 + 10;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

int N;
ld d[MAXN][MAXN];

void Solve(void) {
  cin >> N;
  vector<pii> ps;
  for (int i = 1; i <= N; i ++) {
    int u, v; cin >> u >> v;
    ps.pb(mp(u, v));
  }
  sort(all(ps), [&](pii &u, pii &v) {
    if (u.fi != v.fi) return u.fi < v.fi;
    return u.se < v.se;
  });

  for (int i = 1; i <= N; i ++) {
    for (int j = 1; j <= N; j ++) {
      int sumsq = (ps[i - 1].first - ps[j - 1].first) * (ps[i - 1].first - ps[j - 1].first) + (ps[i - 1].second - ps[j - 1].second) * (ps[i - 1].second - ps[j - 1].second);
      d[i][j] = sqrtl(sumsq);
    }
  }
  
  vector<vector<ld>> g(N + 1, vector<ld> (N + 1, 1e18));
  vector<vector<ld>> f(N + 1, vector<ld> (N + 1, 1e18));
  
  for (int i = N; i >= 1; i --) {
    f[i][i] = 0;
    g[i][i] = 0;
    
    for (int j = i + 1; j <= N; j ++) {
      for (int a = i; a <= j; a ++) {
        g[i][j] = min(g[i][j], f[i][a] + d[a][j]);
        f[i][j] = min(f[i][j], g[i][a] + f[a][j]);
        cout << i << " " << a << " " << j << " " << f[i][a] << " " << d[a][j] << "\n";
      }
    }

    for (int j = i + 1; j <= N; j ++) {
      for (int a = i; a < j; a ++) {
      }
      
      // cout << i << " " << j << " " << f[i][j] << "\n";
    }
  }

  cout << f[1][N] << "\n";
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
