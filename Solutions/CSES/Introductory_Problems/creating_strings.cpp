#include<bits/stdc++.h>
#define ll long long
#define st first
#define nd second
using namespace std;
const int maxn = 4e6;
const int base = 31;
const long long mod = 1e9 + 11;
struct kien{
    int x, y;
};
 
bool operation(kien &a, kien &b)
{
  return a.x > b.x || (a.x == b.x && a.y < b.y);
}
vector<int>adj[maxn];
long long a[maxn], dist[maxn], par[maxn];
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int cur[n];
    for(int i = 0; i < n; i ++) cur[i] = (s[i] - 'a');
    sort(cur, cur + n);
    //for(int i = 0; i < n; i ++) cout << cur[i];
    vector<string>ans;
    do{
        string curr_s;
        for(int i = 0; i < n; i ++){
            curr_s += char(cur[i] + 'a');
        }
        ans.push_back(curr_s);
    }while(next_permutation(cur, cur + n));
    cout << ans.size() << "\n";
    for(auto i : ans) cout << i << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int Tests = 1;
    while(Tests --){
        solve();
    }
}