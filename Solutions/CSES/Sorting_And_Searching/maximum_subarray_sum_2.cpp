#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  int N, A, B; cin >> N >> A >> B;
  vector<i64> pref(N + 1, 0);
  multiset<i64> ms;
  i64 ans = LLONG_MIN;
  for (int i = 1; i <= N; i ++) {
    cin >> pref[i];
    pref[i] += pref[i - 1];
    if (i >= A) {
      ms.insert(pref[i - A]);
    }
    if (i > B) {
      ms.erase(ms.find(pref[i - B - 1]));
    }
    if (i >= A) ans = max(ans, pref[i] - (*ms.begin()));
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}