#include <bits/stdc++.h>
#define int64_t long long
#define double long double
using namespace std;
using type = int64_t;
const long long mod = 1000000007, inf = 1e18;
const int base = 33;
const int N = 4e5 + 10;
const int LG = 20;
 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
struct Project{
    int a, b, v;
};
vector<pair<int, int>>Add[N];
vector<Project>v;
vector<int>compress;
int find_pos(int val)
{
    return lower_bound(compress.begin(), compress.end(), val) - compress.begin() + 1;
}
int64_t f[N];
void Solve()
{
    int n; cin >> n;
    for(int i = 0; i < n; i ++){
        int a, b, add; cin >> a >> b >> add;
        v.push_back({a, b, add});
        compress.push_back(a);
        compress.push_back(b);
    }
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
 
    sort(v.begin(), v.end(), [&](Project &p, Project &q){
        return p.b < q.b;
    });
    for(Project p : v){
        Add[find_pos(p.b)].push_back(make_pair(find_pos(p.a), p.v));
    }
    int m = compress.size();
    for(int i = 1; i <= m; i ++){
        f[i] = f[i - 1];
        for(auto p : Add[i]){
            f[i] = max(f[i], f[p.first - 1] + 1LL * p.second);
        }
    }
    cout << f[m];
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(fopen("guard.in", "r")){
        freopen("guard.in", "r", stdin);
        freopen("guard.out", "w", stdout);
    }
    if(fopen("A.inp", "r")){
        freopen("A.inp", "r", stdin);
        freopen("A.out", "w", stdout);
    }
    int tc = 1;
    //cin >> tc;
    while(tc --){
        Solve();
    }
}