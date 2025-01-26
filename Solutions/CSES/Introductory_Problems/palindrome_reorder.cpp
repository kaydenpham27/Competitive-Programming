#include <bits/stdc++.h>
#define ll long long
#define st first
#define sc second
#define pb push_back
 
using namespace std;
const int maxn = 2e6 + 69;
const int base = 131;
const ll mod = 1e9 + 7;
 
ll a[maxn];
 
long long Pow(int n, int k)
{
    if(k == 0) return 1;
    if(k == 1) return n;
    ll x = Pow(n, k/2) % mod;
    if(k % 2 != 0) return (x * x % mod) * n % mod;
    else return x * x % mod;
}
 
int main()
{
    string s;
    cin >> s;
    vector<char> cur;
    for(int i = 0; i < s.size(); i ++){
        if(a[s[i] - 'A'] == 0) cur.pb(s[i]);
        a[s[i] - 'A'] ++;
    }
    int tmp = 0, flag = 1;
    for(auto j : cur){
        if(a[j - 'A'] % 2 != 0){
            tmp ++;
        }
    }
    if(tmp > 1){
        cout << "NO SOLUTION";
        return 0;
    }
    char d = 'x';
    for(auto j : cur){
        if(a[j - 'A'] % 2 != 0){
            d = j;
            continue;
        }
        for(int i = 0; i < a[j - 'A']/2; i ++){
            cout << j;
        }
    }
    for(int i = 0; i < a[d - 'A']; i ++){
        cout << d;
    }
    for(int j = cur.size() - 1; j >= 0; j --){
        if(a[cur[j] - 'A'] % 2 != 0) continue;
        for(int i = 0; i < a[cur[j] - 'A']/2; i ++){
            cout << cur[j];
        }
    }
}