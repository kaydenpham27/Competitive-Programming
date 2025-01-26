#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  int N; cin >> N;
  vector<array<int, 3>> v(N);
  for (int i = 0; i < N; i ++) {
    cin >> v[i][0] >> v[i][1];
    v[i][2] = i;
  }
  sort(all(v), [&](const array<int, 3> &lf, const array<int, 3> &rg) {
    if (lf[0] != rg[0]) return lf[0] < rg[0];
    return lf[1] > rg[1];
  });
  vector<bool> contained(N, false), contains(N, false);
  int mx = 0;
  for (int i = 0; i < N; i ++) {
    int id = v[i][2];
    // cout << id << " " << v[i][0] << " " << v[i][1] << "\n";
    if (v[i][1] <= mx) {
      contained[id] = true;
    }
    // cout << contained[id] << "\n";
    mx = max(mx, v[i][1]);
  }
  int mn = INT_MAX;
  for (int i = N - 1; i >= 0; i --) {
    int id = v[i][2];
    if (v[i][1] >= mn) {
      contains[id] = true;
    }
    mn = min(mn, v[i][1]);
  }
  for (int i = 0; i < N; i ++) cout << contains[i] << " \n"[i == N - 1];
  for (int i = 0; i < N; i ++) cout << contained[i] << " \n"[i == N - 1];
} 
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}