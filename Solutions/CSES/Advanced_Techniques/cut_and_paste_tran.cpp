#include <bits/stdc++.h>
#define null NULL
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n, m;
string s;
 
struct Node{
    char val;
    int prior, cnt;
    Node *l, *r;
    Node(char c) : val(c), prior(rand()), cnt(1), l(null), r(null) {}
} *root;
 
inline int Size(Node *x){
    return x ? x -> cnt : 0;
}
 
void Merge(Node *&root, Node *l, Node *r){
    if (l == null || r == null){
        root = l ? l : r;
        return;
    }
 
    if (l -> prior < r -> prior){
        Merge(r -> l, l, r -> l);
        root = r;
    }
    else{
        Merge(l -> r, l -> r, r);
        root = l;
    }
 
    root -> cnt = 1 + Size(root -> l) + Size(root -> r);
}
 
void Split(Node *root, Node *&l, Node *&r, int key, int add = 0){
    if (!root) return void(l = r = null);
 
    int cur = add + Size(root -> l);
    if (cur < key){
        Split(root -> r, root -> r, r, key, cur + 1);
        l = root;
    }
    else{
        Split(root -> l, l, root -> l, key, add);
        r = root;
    }
 
    root -> cnt = 1 + Size(root -> l) + Size(root -> r);
}
 
ostream &operator<<(ostream &os, Node *n){
	if (!n) return os;
	os << n -> l;
	os << n -> val;
	os << n -> r;
	return os;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    cin >> n >> m >> s;
 
    for (char c : s) Merge(root, root, new Node(c));
 
    //cout << endl;
 
    for (int i = 1; i <= m; ++ i){
        int l, r; cin >> l >> r;
 
        Node *a, *b, *c, *d;
        Split(root, a, b, l - 1);
        Split(b, c, d, r - l + 1);
 
        //cout << a << endl;
        //cout << b << endl;
        //cout << c << endl;
        //cout << d << endl;
 
        Merge(root, a, d);
        Merge(root, root, c);
    }
 
    cout << root;
}