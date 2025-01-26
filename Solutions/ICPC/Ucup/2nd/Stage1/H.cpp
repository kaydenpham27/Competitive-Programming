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

const int MAXN = 1e5 + 5;
const int MAXW = 1e6;

string S; int x[MAXN], t; i64 suff[MAXN]; 
void Solve(void) {
  cin >> S; 
  t = 0;
  int N = (int)S.size(); S = " " + S;
  for (int i = 1; i <= N; i ++) {
    int c = S[i] - '0';
    if (t & 1) c = 1 - c;
    t += (1 - c) + 1;
    x[i] = t;
  }
  suff[N + 1] = 0;
  for (int i = N; i >= 1; i --) {
    suff[i] = suff[i + 1] + x[i];
  }
  i64 ans = 0;
  for (int i = 1; i <= N; i ++) {
    suff[i] -= 1LL * (x[i] - 1) * (N - i + 1);
    if (S[i] == '0') suff[i] += N - i + 1;
    ans += suff[i];
  }
  cout << ans << "\n";
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