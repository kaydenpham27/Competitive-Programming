#include <bits/stdc++.h>
#define int long long
#define double long double
 
using namespace std;
 
const int O = 2e3 + 5;
 
int n, a, b;
double f[O][O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> a >> b;
 
    f[0][0] = 1;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j <= 6 * i; ++ j){
            if (!f[i][j]) continue;
            for (int z = 1; z <= 6; ++ z){
                f[i + 1][j + z] += 1. / 6 * f[i][j];
            }
        }
    }
 
    double res = 0;
    for (int i = a; i <= b; ++ i) res += f[n][i];
 
    cout << fixed << setprecision(6) << res;
}