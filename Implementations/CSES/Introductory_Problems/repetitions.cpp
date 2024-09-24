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
    string s;
    cin >> s;
    int n = s.size();
    char d = 'k';
    int cnt = 0, maxx = 1;
    for(int i = 0; i < n; i ++){
        if(s[i] == d){
            cnt ++;
            maxx = max(maxx, cnt);
        }
        else{
            d = s[i];
            cnt = 1;
        }
    }
    cout << maxx;
 
}