#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define i128 __int128
#define int long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 2e5 + 5;
const int MAXW = 1e6;

int N;
void Solve(void) {
  cin >> N;
  vector<pair<int, int>> p(N + 2);
  vector<int> suff(N + 2, 0);
  for (int i = 1; i <= N; i ++) {
    cin >> p[i].first >> p[i].second;
  }
  int ans = 0;
  int add = 0;
  suff[N + 1] = INT_MAX;
  for (int i = 1; i < N; i ++) {
    suff[i] = min(suff[i + 1], p[i].second);
    p[i].first -= add;
    if (p[i].second <= p[i + 1].second) {

    } else if (p[i].second > p[i + 1].second && p[i].first <= p[i + 1].second) {
      p[i].first = 0;
    } else {
      add += suff[i];
      suff[i] = p[i].second;
      ans ++;
    }
  } 
  cout << ans + 1 << "\n";
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