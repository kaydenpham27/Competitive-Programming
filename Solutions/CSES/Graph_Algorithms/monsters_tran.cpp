#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 2e6 + 5;
 
int n, m, sta, f[O], d[O], dd[O], trace[O];
deque <int> Mons;
vector <int> g[O];
char a[O];
 
int conv(int x, int y){
    return (x - 1) * m + y;
}
 
pair <int, int> rconv(int x){
    int j = (x % m) + (x % m == 0 ? m : 0);
    return make_pair((x - j) / m + 1, j);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i){
        string s; cin >> s;
        for (int j = 1; j <= m; ++ j){
            int x = conv(i, j);
            //cin >> a[x];
            a[x] = s[j - 1];
 
            if (a[x] == 'M') Mons.push_back(x);
            else{
                if ((a[x] == 'A' || a[x] == '.') && (i == 1 || i == n || j == 1 || j == m)) dd[x] = 1;
            }
 
            if (a[x] == 'A') sta = x;
 
            if (a[x] != '#'){
                int ni = i - 1;
                int nj = j;
                int nx = conv(ni, nj);
 
                if (i && a[nx] != '#'){
                    g[nx].push_back(x);
                    g[x].push_back(nx);
                }
 
                ni = i;
                nj = j - 1;
                nx = conv(ni, nj);
 
                if (j && a[nx] != '#'){
                    g[nx].push_back(x);
                    g[x].push_back(nx);
                }
            }
        }
    }
 
    for (int i = 1; i <= n * m; ++ i){
        d[i] = a[i] == 'M' ? 0 : O + O;
    }
 
    while (Mons.size()){
        int u = Mons.front();
        Mons.pop_front();
 
        for (int v : g[u]){
            if (d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                Mons.push_back(v);
            }
        }
    }
 
    for (int i = 1; i <= n * m; ++ i){
        f[i] = d[i];
        //cout << "check " << i << " : " << d[i] << endl;
    }
 
    int en = 0;
    queue <int> q; q.push(sta); f[sta] = 0;
 
    while (q.size()){
        int u = q.front();
        q.pop();
 
        if (dd[u]){
            en = u;
            break;
        }
 
        for (int v : g[u]){
            if (f[v] > f[u] + 1){
                f[v] = f[u] + 1;
                trace[v] = u;
                q.push(v);
            }
        }
    }
 
    if (!en) return cout << "NO", 0;
 
    cout << "YES\n";
 
    string res = "";
    for (int i = en; i != sta; i = trace[i]){
        auto x = rconv(i);
        auto y = rconv(trace[i]);
 
        if (y.first + 1 == x.first) res += 'D';
        if (y.first - 1 == x.first) res += 'U';
        if (y.second - 1 == x.second) res += 'L';
        if (y.second + 1 == x.second) res += 'R';
    }
 
    reverse(res.begin(), res.end());
    cout << res.size() << "\n" << res;
 
}
/**
**/