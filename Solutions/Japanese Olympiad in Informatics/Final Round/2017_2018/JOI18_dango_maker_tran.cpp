#include <bits/stdc++.h>
#define ii pair <int, int>
#define fi first.first
#define se first.second
#define th second

using namespace std;

const int O = 3e3 + 5;
const int base = 500;
const int mod = 998244353;

int n, m, cnt, cal, c[O][O];
bool dd[2][O][O];
string a[O];

vector <pair <ii, int>> g(pair <ii, int> u){
    vector <pair <ii, int>> res;

    int i = u.se;
    int j = u.th;
    if (u.fi == 0){
        if (i > 2 && (c[i - 2][j + 2] & 2)){
            res.push_back(make_pair(make_pair(1, i - 2), j + 2));
        }

        if (i > 1 && (c[i - 1][j + 1] & 2)){
            res.push_back(make_pair(make_pair(1, i - 1), j + 1));
        }

        if (c[i][j] & 2){
            res.push_back(make_pair(make_pair(1, i), j));
        }
    }

    if (u.fi == 1){
        if (j > 2 && (c[i + 2][j - 2] & 1)){
            res.push_back(make_pair(make_pair(0, i + 2), j - 2));
        }

        if (j > 1 && (c[i + 1][j - 1] & 1)){
            res.push_back(make_pair(make_pair(0, i + 1), j - 1));
        }

        if (c[i][j] & 1){
            res.push_back(make_pair(make_pair(0, i), j));
        }
    }

    return res;
}

int dfs(pair <ii, int> u){
    vector <int> f[2], b;

    queue <pair <ii, int>> q;
    q.push(u);

    int turn = u.fi;
    dd[u.fi][u.se][u.th] = 1; cal = 0;
    while (q.size()){
        u = q.front(); q.pop();

        //cout << u.fi << " " << u.se << " " << u.th << endl;

        if (turn != u.fi) b.push_back(cal);

        cal = turn == u.fi ? cal + 1 : 1;
        turn = u.fi;

        auto adj = g(u);
        for (auto v : adj){
            if (!dd[v.fi][v.se][v.th]){
                dd[v.fi][v.se][v.th] = 1;
                q.push(v);
            }
        }
    }

    b.push_back(cal);

    int m = b.size() - 1;

    f[0].resize(m + 1);
    f[1].resize(m + 1); f[1][0] = b[0];
    for (int i = 1; i <= m; ++ i){
        f[1][i] = f[0][i - 1] + b[i];
        f[0][i] = max(f[0][i - 1], f[1][i - 1]);
    }

    return max(f[0][m], f[1][m]);
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i){
        cin >> a[i]; a[i] = " " + a[i];
        for (int j = 1; j <= m; ++ j){
            if (a[i][j] == 'W' && j >= 3){
                c[i][j - 2] += (a[i][j - 2] == 'R' && a[i][j - 1] == 'G');
            }

            if (a[i][j] == 'W' && i >= 3){
                c[i - 2][j] += 2 * (a[i - 2][j] == 'R' && a[i - 1][j] == 'G');
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            if (c[i][j] > 0){
                cnt = cal = 0;
                //cout << "debug " << i << " " << j << endl;
                if ((c[i][j] & 1) && !dd[0][i][j]){
                    cnt = dfs(make_pair(make_pair(0, i), j));
                }

                if ((c[i][j] & 2) && !dd[1][i][j]){
                    cnt = dfs(make_pair(make_pair(1, i), j));
                }
                //cout << cnt << " " << cal << endl;
                //cout << "end" << endl;

                res += cnt;
            }
        }
    }

    cout << res;
}
/***
5 5
RGWRR
GRRGW
WRGWR
RGWRG
XWRGW
***/