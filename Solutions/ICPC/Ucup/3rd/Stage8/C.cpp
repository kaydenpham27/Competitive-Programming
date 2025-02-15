// FPTU UWR
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 4e5 + 10;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

int K;
void Solve(void) {
  cin >> K;
  vector<int> idL(K * 4, -1), idR(K * 4, -1);
  
  vector<pair<int, int>> edges;
  int id = 0;
  int L = 0, R = 1;
  vector<int> col(K * 4, 0);
  for (int i = 1; i <= K; i ++) {
    idL[i] = ++id;
    col[idL[i]] = L;
    L = 1 - L;

    idR[i] = ++id;
    col[idR[i]] = R;
    R = 1 - R;

    for (int j = i - 1; j >= 1; j --) {
      if ((i - j) % 2 == 0) {
        edges.pb(mp(idL[i], idR[j]));      
        edges.pb(mp(idR[i], idL[j]));
      }
      else {
        edges.pb(mp(idL[i], idL[j]));
        edges.pb(mp(idR[i], idR[j]));
      }    
    }
  }
  idL[K + 1] = ++id;
  col[idL[K + 1]] = L;
  L = 1 - L;
  for (int j = K; j >= 1; j --) {
    if ((K + 1 - j) % 2 == 0) {
      edges.pb(mp(idL[K + 1], idR[j]));      
    }
    else {
      edges.pb(mp(idL[K + 1], idL[j]));
    }    
  }
  idL[K + 2] = ++id;
  col[idL[K + 2]] = L;
  L = 1 - L;
  for (int j = K + 1; j >= 1; j --) {
    if ((K + 2 - j) % 2 == 0) {
      edges.pb(mp(idL[K + 2], idR[j]));      
    }
    else {
      edges.pb(mp(idL[K + 2], idL[j]));
    }    
  }

  cout << (K + 1) * 2 << " " << (int)edges.size() << " " << 2 << "\n";
  for (int i = 1; i <= 2 * (K + 1); i ++) cout << col[i] + 1 << " \n"[i == 2 * (K + 1)];
  for (auto [u, v] : edges) {
    cout << u << " " << v << "\n";
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
