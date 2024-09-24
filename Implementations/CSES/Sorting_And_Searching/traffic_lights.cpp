#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  multiset<int> ms;
  multiset<int> lights; 
  int N, X; cin >> X >> N;
  lights.insert(0); lights.insert(X);
  ms.insert(X);
  for (int i = 0; i < N; i ++) {
    int p; cin >> p;
    auto nxt = lights.upper_bound(p);
    int rg = (*nxt); nxt --;
    int lf = (*nxt);
    int gap = rg - lf;
    ms.erase(ms.find(gap));
    lights.insert(p);
    ms.insert(p - lf);
    ms.insert(rg - p);
    cout << (*ms.rbegin()) << " ";
  }
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}