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

const int MAXN = 2e5 + 5;
const int MAXW = 1e6;

int cyz[300], rxy[300], ryz[300], czx[300], rzx[300], cxy[300]; char yz[300][300], zx[300][300], xy[300][300]; 
void Solve(void) {
  int N; cin >> N;
  for (int i = 1; i <= N; i ++) {
    for (int j = 1; j <= N; j ++) {
      cin >> yz[i][j];
      if (yz[i][j] == '1') {
        ryz[i] ++;
        cyz[j] ++;
      }
    }
  }
  for (int i = 1; i <= N; i ++) {
    for (int j = 1; j <= N; j ++) {
      cin >> zx[i][j];
      if (zx[i][j] == '1') {
        rzx[i] ++;
        czx[j] ++;
      }
    }
  }
  for (int i = 1; i <= N; i ++) {
    for (int j = 1; j <= N; j ++) {
      cin >> xy[i][j];
      if (xy[i][j] == '1') {
        rxy[i] ++;
        cxy[j] ++;
      }
    }
  }
  for (int i = 1; i <= N; i ++) {
    if (cyz[i] == 0 & rxy[i]) {
      cout << "No" << "\n";
      return;
    }
    if (cyz[i] & rxy[i] == 0) {
      cout << "No" << "\n";
      return;
    }

    if (czx[i] == 0 & ryz[i]) {
      cout << "No" << "\n";
      return;
    }
    if (czx[i] & ryz[i] == 0) {
      cout << "No" << "\n";
      return;
    }

    if (rzx[i] == 0 & cxy[i]) {
      cout << "No" << "\n";
      return;
    }
    if (rzx[i] & cxy[i] == 0) {
      cout << "No" << "\n";
      return;
    }
  }
  cout << "Yes" << "\n";
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
