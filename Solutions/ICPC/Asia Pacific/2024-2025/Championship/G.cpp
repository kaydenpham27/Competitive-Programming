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

const int MAXN = 4e5 + 10;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

void Solve(void) {
  int N, M; cin >> N >> M;
  string S, T; cin >> S >> T;
  vector<int> cntS(N + 2, 0), cntT(M + 2, 0);
  S = " " + S;
  T = " " + T;
  for (int i = 1; i <= N; i ++) cntS[i] = cntS[i - 1] + (S[i] == '1');
  for (int i = 1; i <= M; i ++) cntT[i] = cntT[i - 1] + (T[i] == '1');

  vector<int> s0, t0;
  for (int i = 1; i <= N; i ++) if (S[i] == '0') s0.pb(i);
  for (int i = 1; i <= M; i ++) if (T[i] == '0') t0.pb(i);
  
  int sz1 = s0.size();
  int sz2 = t0.size();
  if (sz1 < sz2 || sz1 && (sz2 == 0)) {
    cout << "no" << "\n";
    return;
  }

  if (sz1 == 0) {
    cout << (N >= M ? "yes" : "no") << "\n";
    return;
  }

  if (cntS[s0[0]] < cntT[t0[0]] || 
    (cntS[N] - cntS[s0.back() - 1] < cntT[M] - cntT[t0.back() - 1]) 
  ) {
    cout << "no" << "\n";
    return;
  }

  int p = 1;
  for (int i = 1; i < sz2; i ++) {
    bool works = false;
    while (p < sz1) {
      int haves = cntS[s0[p]] - cntS[s0[p - 1] - 1];
      int havet = cntT[t0[i]] - cntT[t0[i - 1] - 1];
      p ++;
      if (haves >= havet) {
        works = true;
        break;
      }
    }
    if (!works) {
      cout << "no" << "\n";
      return;
    }
  }
  cout << "yes" << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; cin >> Tests;    
  for (int i = 1; i <= Tests; i ++) {
    // cout << "Case " << i << ": ";
    Solve();    
  }
}
