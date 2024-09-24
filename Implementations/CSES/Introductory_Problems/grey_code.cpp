#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
vector<string> greycode(int N) {
  if (N == 1) {
    vector<string> ans = {"0", "1"};
    return ans;
  }
  vector<string> upper = greycode(N - 1);
  vector<string> lower = upper;
  reverse(lower.begin(), lower.end());
  for (string &x : upper) {
    x = "0" + x;
  }
  for (string &x : lower) {
    x = "1" + x;
    upper.pb(x);
  }
  return upper;
}
void Solve(void) {
  int N; cin >> N;
  vector<string> ans = greycode(N);
  for (string x : ans) cout << x << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}