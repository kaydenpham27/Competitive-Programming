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

const int MAXN = 2e5 + 10;
const int MOD = 235813;
const i64 INF = INT_MAX/2;

int N, Q, r[MAXN], c[MAXN], lfr[MAXN], lfc[MAXN];
void Solve(void) {  
  cin >> N >> Q;
  for (int i = 1; i <= N; i ++) cin >> r[i];
  for (int i = 1; i <= N; i ++) cin >> c[i];

  for (int i = 1; i <= N; i ++) {
    bool cond = ((r[i] % 2 != r[i - 1] % 2) || i == 1);
    lfr[i] = (cond ? i : lfr[i - 1]);
  }
  for (int i = 1; i <= N; i ++) {
    bool cond = ((c[i] % 2 != c[i - 1] % 2) || i == 1);
    lfc[i] = (cond ? i : lfc[i - 1]);
  }
  while (Q --) {
    int ra, ca, rb, cb; cin >> ra >> ca >> rb >> cb;
    if (ra > rb) swap(ra, rb);
    if (ca > cb) swap(ca, cb);
    if (lfr[rb] > ra) cout << "NO" << "\n";
    else if (lfc[cb] > ca) cout << "NO" << "\n";
    else cout << "YES" << "\n";
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