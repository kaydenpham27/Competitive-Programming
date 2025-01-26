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
    for(int i = 1; i < n; i ++){
        int d;
        cin >> d;
        a[d] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == 0){
            cout << i;
            break;
        }
    }
 
}