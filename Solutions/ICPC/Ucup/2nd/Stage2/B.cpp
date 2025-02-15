// FPTU UWR
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 4e5 + 10;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

int getDay(int month, int year) {
  if (month == 1 || month == 3 || month == 5 || month == 7 || 
      month == 8 || month == 10 || month == 12) {
    return 31;      
  }
  if (month == 2) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
      return 29;
    }
    return 28;
  }
  return 30;
}
void Solve(void) {
  int day = 1, p = 3;
  vector<int> ans(5000, 0);
  for (int year = 1970; year <= 2037; year ++) {
    int month = 1;
    int row = 1;
    while (month <= 12) {
      int mx = getDay(month, year);
      if (day + 7 <= mx) {
        day += 7; row ++;
      } else {
        p = (p + mx - day + 1);
        if (p >= 8) row ++;
        p %= 7;
        day = 1;
        month ++;
        row ++;
      }
    }
    ans[year] = row - 1;
  }
  int Y; cin >> Y; 
  cout << ans[Y] << "\n";
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
