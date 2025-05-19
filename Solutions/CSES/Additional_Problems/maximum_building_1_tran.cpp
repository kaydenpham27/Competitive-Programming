#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 1e3 + 5;
 
int n, m, res, L[O][O], R[O][O], val[O][O], last[O][O];
char a[O][O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i){
        stack <int> s;
        for (int j = 1; j <= m; ++ j){
            cin >> a[i][j];
            last[i][j] = last[i - 1][j];
            if (a[i][j] == '*') last[i][j] = i;
            val[i][j] = i - last[i][j];
            while (s.size() && val[i][s.top()] >= val[i][j]) s.pop();
            L[i][j] = s.size() ? s.top() : 0;
            //cout << i << " " << j << " L: " << val[i][j] << " " << L[i][j] << "\n";
            s.push(j);
        }
    }
 
    for (int i = 1; i <= n; ++ i){
        stack <int> s;
        for (int j = m; j >= 1; -- j){
            while (s.size() && val[i][s.top()] >= val[i][j]) s.pop();
            R[i][j] = s.size() ? s.top() : m + 1;
            //cout << i << " " << j << " R: " << val[i][j] << " " << R[i][j] << "\n";
            res = max(res, val[i][j] * (R[i][j] - L[i][j] - 1));
            s.push(j);
        }
    }
 
    cout << res;
}
/**
aybabtu
**/