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

int N, K, M, F;
void Solve(void) {
  cin >> N >> K >> M >> F;
  vector<pair<i128, int>> vs(N);
  for (int i = 0; i < N; i ++) vs[i] = mp((i128)0, i);
  for (int i = 0; i < K; i ++) {
    for (int j = 0; j < M; j ++) {
      int x; cin >> x; x --;
      vs[x].first |= ((i128)1 << i);
    }
  }

  sort(all(vs));

  while (F --) {
    string S; cin >> S;
    i128 mask = 0;
    for (int i = 0; i < K; i ++) {
      if (S[i] == 'Y') mask |= ((i128)1 << i);
    }

    int p = lower_bound(all(vs), mp(mask, -1LL)) - vs.begin();

    if (p < 0 || p >= N || vs[p].first != mask) {
      cout << 0 << "\n";
    } else {
      if (p < N - 1 && vs[p + 1].first == mask) cout << 0 << "\n";
      else cout << vs[p].second + 1 << "\n";
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