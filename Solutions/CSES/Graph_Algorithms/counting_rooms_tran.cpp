#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 1e3 + 5;
 
int n, m, d[O][O];
char a[O][O];
 
int check(int x, int y){
    return (1 <= x && x <= n) && (1 <= y && y <= m) && !d[x][y];
}
 
void dfs(int x, int y){
    d[x][y] = 1;
    if (check(x + 1, y)) dfs(x + 1, y);
    if (check(x, y + 1)) dfs(x, y + 1);
    if (check(x - 1, y)) dfs(x - 1, y);
    if (check(x, y - 1)) dfs(x, y - 1);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            cin >> a[i][j];
            if (a[i][j] == '#') d[i][j] = 1;
        }
    }
 
    int res = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            if (check(i, j)){
                dfs(i, j);
                res += 1;
            }
        }
    }
 
    cout << res;
}