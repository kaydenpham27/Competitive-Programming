#include <bits/stdc++.h>
#define ll long long
#define st first
#define sc second
#define pb push_back
 
using namespace std;
 
const int maxn = 2e5 + 69;
const int base = 131;
const ll mod = 1e9 + 7;
 
ll a[maxn];
 
int main()
{
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        if(a[i] < a[i - 1]){
            ans += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }
    cout << ans;
 
}