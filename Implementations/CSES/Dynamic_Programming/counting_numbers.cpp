#include <bits/stdc++.h>
#define int64_t long long
#define double long double
using namespace std;
using type = int64_t;
const long long mod = 1000000007, inf = 1e18;
const int base = 33;
const int N = 4e6 + 10;
const int LG = 20;
 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
string s;
int64_t f[20][12][3][3];
int64_t dp(int pos, int prev, bool under, bool started)
{
    if(pos == s.size()){
        return 1;
    }
    if(prev != -1 && f[pos][prev][under][started] != -1)
        return f[pos][prev][under][started];
    int64_t ans = 0;
    for(int i = 0; i <= 9; i ++){
        int digit_diff = s[pos] - '0';
        if(!under && i > digit_diff) break;
 
        bool is_under = under | (i < digit_diff);
        bool is_started = started | (i != 0);
 
        if(i == prev && !started){
            ans = ans + dp(pos + 1, i, is_under, is_started);
        }
 
        if(i != prev)
            ans = ans + dp(pos + 1, i, is_under, is_started);
    }
    return f[pos][prev][under][started] = ans;
}
int64_t Count(int64_t x)
{
    memset(f, -1, sizeof(f));
    s = to_string(x);
    return dp(0, -1, 0, 0);
}
void Solve(void)
{
    int64_t a, b; cin >> a >> b;
    cout << Count(b) - Count(a - 1);
}
 
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
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