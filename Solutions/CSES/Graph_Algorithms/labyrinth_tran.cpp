#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 1e3 + 5;
const int inf = 1e18;
 
int n, m, d[O][O];
pair <int, int> sta, en, trace[O][O];
char a[O][O];
 
int check(int x, int y){
    return a[x][y] != '#' && (1 <= x && x <= n) && (1 <= y && y <= m);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            cin >> a[i][j];
            if (a[i][j] == 'A') sta = {i, j};
            if (a[i][j] == 'B') en = {i, j};
        }
    }
 
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j) d[i][j] = inf;
    }
 
    d[sta.first][sta.second] = 0;
    priority_queue <pair <int, pair <int, int>>, vector <pair <int, pair <int, int>>>, greater <pair <int, pair <int, int>>>> q;
 
    q.push(make_pair(0, sta));
    while (q.size()){
        int dist = q.top().first;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
 
        if (dist != d[x][y]) continue;
 
        if (check(x + 1, y) && d[x + 1][y] > dist + 1){
            d[x + 1][y] = dist + 1;
            trace[x + 1][y] = {x, y};
            q.push(make_pair(dist + 1, make_pair(x + 1, y)));
        }
 
        if (check(x - 1, y) && d[x - 1][y] > dist + 1){
            d[x - 1][y] = dist + 1;
            trace[x - 1][y] = {x, y};
            q.push(make_pair(dist + 1, make_pair(x - 1, y)));
        }
 
        if (check(x, y + 1) && d[x][y + 1] > dist + 1){
            d[x][y + 1] = dist + 1;
            trace[x][y + 1] = {x, y};
            q.push(make_pair(dist + 1, make_pair(x, y + 1)));
        }
 
        if (check(x, y - 1) && d[x][y - 1] > dist + 1){
            d[x][y - 1] = dist + 1;
            trace[x][y - 1] = {x, y};
            q.push(make_pair(dist + 1, make_pair(x, y - 1)));
        }
    }
 
    if (d[en.first][en.second] >= inf) return cout << "NO", 0;
 
    cout << "YES\n";
    cout << d[en.first][en.second] << endl;
    string ans = "";
    for (pair <int, int> i = en; i != sta;){
        pair <int, int> par = trace[i.first][i.second];
        if (par.first == i.first + 1) ans += 'U';
        if (par.first == i.first - 1) ans += 'D';
        if (par.second == i.second + 1) ans += 'L';
        if (par.second == i.second - 1) ans += 'R';
        i = par;
    }
 
    reverse(ans.begin(), ans.end());
    cout << ans;
}