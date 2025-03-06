// FPTU UWR
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
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

string Ask1(int p) {
  cout << "type " << p << "\n";
  fflush(stdout);
  string ans; cin >> ans; return ans;
}
int Ask2(int p) {
  cout << "multi " << p << "\n";
  fflush(stdout);
  int ans; cin >> ans; return ans;
}
void Answer(int p) {
  cout << "answer " << p << "\n";
  fflush(stdout);
}
void Solve(void) {
  int N; cin >> N;
  int l = 1, h = N; while (l <= h) {
    int mid = (l + h)/2;
    if (Ask1(mid) == "rose") l = mid + 1;
    else h = mid - 1;
  }
  // cout << h << "\n";
  l = h;
  l = min(l, N);
  int cur = Ask2(l);
  if (l == 0) {
    int cur1 = Ask2(l + 1);
    if (cur1 == 0) {
      Answer(0);
    } else {
      Answer(cur1);
    }
  } else if (l == N) {
    int cur1 = Ask2(l - 1);
    if (cur1 == 0) {
      // All Rose
      Answer(N);
    } else {
      int numLily = cur1;
      int numRose = 1 + l - 1 - numLily;
      Answer(numRose);
    }
  } else {
    int curLf = Ask2(l - 1);
    int curRg = Ask2(l + 1);

    int numRose = curRg - cur;
    int numLily = curLf - cur;

    Answer(numRose + l - numLily);
  }
}
signed main() {
  // ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; cin >> Tests;    
  for (int i = 1; i <= Tests; i ++) {
    // cout << "Case " << i << ": ";
    Solve();    
  }
}
