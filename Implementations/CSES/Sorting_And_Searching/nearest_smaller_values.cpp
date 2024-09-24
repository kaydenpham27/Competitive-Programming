#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  int N; cin >> N;
  vector<int> a(N + 1, 0);
  stack<int> st; st.push(0);
  for (int i = 1; i <= N; i ++) {
    cin >> a[i];
    while (!st.empty() && a[st.top()] >= a[i]) {
      st.pop();
    }
    cout << st.top() << " ";
    st.push(i);
  }
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}