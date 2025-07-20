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
  int en; cin >> en;
  if (en < 4) {
    cout << en << "\n";
    return;
  }

  int pow3 = 1;
  int cur = 0;
  int ans = en;

  for (int i = 1; i < 40; i ++) {
    cur += pow3 * 4;
    pow3 *= 3;

    int need = en - cur;
    if (need < 0) break;

    int best = 2 * i;
    for (int j = 0; j < i; j ++) {
      best += need % 3;
      need /= 3; 
    }
    best += need;
    ans = min(ans, best);
  }
  cout << ans << "\n";
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
