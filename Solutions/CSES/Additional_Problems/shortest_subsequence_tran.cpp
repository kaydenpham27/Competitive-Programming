#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 1e6 + 5;
 
int n, c[O], last[4][O];
char d[4];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s; n = s.size();
    c['A'] = 0; d[0] = 'A';
    c['C'] = 1; d[1] = 'C';
    c['G'] = 2; d[2] = 'G';
    c['T'] = 3; d[3] = 'T';
 
    for (int j = 0; j < 4; ++ j) last[j][n] = n;
 
    for (int i = n - 1; i >= 0; -- i){
        for (int j = 0; j < 4; ++ j) last[j][i] = last[j][i + 1];
        last[c[s[i]]][i] = i;
    }
 
    int pos = 0;
    string res = "";
    while (pos <= n){
        int Max = 0;
        for (int i = 0; i < 4; ++ i) Max = (last[Max][pos] > last[i][pos] ? Max : i);
        res += d[Max];
        pos = last[Max][pos] + 1;
    }
 
    cout << res;
}
/**
9 1
9 9 8 2 4 4 3 5 3
**/