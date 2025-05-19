#include <bits/stdc++.h>
#define int long long
#define double long double
 
using namespace std;
 
const int O = 1e2 + 5;
 
int k;
double f[9][9][9][9][O];
 
 
main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> k;
 
  double res = 0;
  for (int x = 1; x <= 8; ++ x){
    for (int y = 1; y <= 8; ++ y){
      f[x][y][x][y][0] = 1;
      for (int z = 0; z < k; ++ z){
        for (int i = 1; i <= 8; ++ i){
          for (int j = 1; j <= 8; ++ j){
            double p = f[x][y][i][j][z];
            if (!p) continue;
 
            int cur = (i > 1) + (i < 8) + (j > 1) + (j < 8);
            p /= cur;
            
            if (i > 1) f[x][y][i - 1][j][z + 1] += p;
            if (i < 8) f[x][y][i + 1][j][z + 1] += p;
 
            if (j > 1) f[x][y][i][j - 1][z + 1] += p;
            if (j < 8) f[x][y][i][j + 1][z + 1] += p;
 
          }
        }
      }
    }
  }
 
  for (int i = 1; i <= 8; ++ i){
    for (int j = 1; j <= 8; ++ j){
      double p = 1;
      for (int x = 1; x <= 8; ++ x){
        for (int y = 1; y <= 8; ++ y){
          p *= (1. - f[x][y][i][j][k]);
        }
      }
      res += p;
    }
  }
 
  cout << fixed << setprecision(6) << res;
 
}