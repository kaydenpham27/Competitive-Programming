#include <bits/stdc++.h>

using namespace std;

const int O = 2e5 + 5;
const int N = (1 << 10) + 5;
const int mod = 1e9 + 7; //998244353;
const int inf = 1e9;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};

int n, f[2][2][O];
vector <int> g[O];
bool a[O];

void dfs(int u, int par = 0){
    int dif0 = 0, dif1 = 0;
    for (int v : g[u]){
        if (v != par){
            dfs(v, u);
            f[0][0][u] += f[0][0][v];
            f[1][1][u] += max({f[1][1][v], f[0][0][v], f[1][0][v]});
            f[0][1][u] += f[0][0][v];
            dif0 = max(dif0, f[0][1][v] - f[0][0][v]);
            dif1 = max(dif1, max(f[1][0][v], f[1][1][v]) - f[0][0][v]);
        }
    }
    f[1][0][u] += a[u];
    f[1][1][u] -= a[u];
    f[0][1][u] = f[0][1][u] + max(max((int)a[u], dif0), a[u] + dif1);
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++ i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++ i){
        char x; cin >> x;
        a[i] = (x == '1');
    }

    dfs(1);

    int res = 0;
    for (int i = 0; i < 2; ++ i){
        for (int j = 0; j < 2; ++ j){
            //if (!(i == 1 && j == 0)){
                //for (int z = 1; z <= n; ++ z) cout << i << " " << j << " " << z << " = " << f[i][j][z] << endl;
            //}
            res = max(res, f[i][j][1]);
        }
    }

    cout << res;
}
/**
5
1 2
2 3
3 4
4 5
2
1 1
2 1
**/