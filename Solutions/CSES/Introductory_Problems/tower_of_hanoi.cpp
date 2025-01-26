#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void solveTower(vector<pair<int, int>> &step, int N, int src, int mid, int des) {
  if (N == 1) {
    step.push_back(mp(src, des));
    return;
  }
  solveTower(step, N - 1, src, des, mid);
  step.push_back(mp(src, des));
  solveTower(step, N - 1, mid, src, des);
}
void Solve(void) {
  int N; cin >> N;
  vector<pair<int, int>> step;
  solveTower(step, N, 1, 2, 3);
  cout << (int)step.size() << "\n";
  for (auto [des, to] : step) {
    cout << des << " " << to << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}