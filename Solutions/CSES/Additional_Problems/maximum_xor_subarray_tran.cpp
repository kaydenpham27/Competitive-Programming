#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n, N, res, sum;
int lim = 30;
 
struct Node{
    int child[30];
} tree[O * 32];
 
void Add(int x){
    int p = 0;
    for (int i = lim - 1; i >= 0; -- i){
        int c = x >> i & 1;
        if (tree[p].child[c] == 0) tree[p].child[c] = ++ N;
        p = tree[p].child[c];
    }
}
 
int Get(int x){
    int cur = 0, p = 0;
    for (int i = lim - 1; i >= 0; -- i){
        int c = x >> i & 1;
        if (tree[p].child[c ^ 1]){
            cur ^= (1 << i);
            p = tree[p].child[c ^ 1];
        }
        else p = tree[p].child[c];
    }
    return cur;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n; Add(0);
    for (int i = 1; i <= n; ++ i){
        int x; cin >> x;
        sum ^= x;
        res = max(res, Get(sum));
        Add(sum);
    }
 
    cout << res;
}
/**
9 1
9 9 8 2 4 4 3 5 3
**/