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
  
int main()
{
    long long n;
    cin >> n;
    if(1LL*n*(n + 1) % 4 != 0){
        cout << "NO";
        return 0;
    }
    vector<int>s;
    long long cur = n, p = 1LL*n*(n + 1)/4;
    while(p != 0){
        if(cur >= p){
            s.pb(p);
            p = 0;
            break;
        }
        s.pb(cur);
        p -= cur;
        cur --;
    }
    cout << "YES" << "\n";
    cout << s.size() << "\n";
    for(auto j : s){
        cout << j << " ";
        a[j] = 1;
    }
    cout << "\n";
    cout << n - s.size() << "\n";
    for(int i = 1; i <= n; i ++){
        if(a[i] == 0){
            cout << i << " ";
        }
    }
}