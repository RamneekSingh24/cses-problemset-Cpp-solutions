#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
class Segtree {
public:
    int n;
    vector<int> t;
    Segtree(int n) {
        this->n  = n;
        this->t.assign(4 * n + 5, 0);
    }
    void build(vector<int> &vec, int tl , int tr , int v) {
        if(tl == tr) {
            t[v] = vec[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(vec, tl, tm, 2*v);
        build(vec, tm+1, tr, 2*v+1);
        t[v] = min(t[2*v], t[2*v+1]);
    }
    int query(int l, int r, int tl, int tr, int v) {
        if(l > r) return 1e9;
        if(l == tl && r == tr) return t[v];
        int tm = (tl + tr)/2;
        return min(query(l, min(r,tm), tl, tm, 2*v), query(max(l,tm+1),r, tm+1,tr,2*v+1));
    }
 
    void update(int pos, int val, int tl, int tr, int v) {
        if (tl == tr) t[v] = val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(pos, val, tl, tm, 2 *v);
            }
            else {
                update(pos,val,tm+1,tr,2*v+1);
            }
            t[v] = min(t[2*v],t[2*v+1]);
        }
    }
 
};
 
 
int main () {
 
    int n; cin >> n;
    int q; cin >> q;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    Segtree st(n);
    st.build(vec,0,n-1,1);
    while(q--) {
        int k, a, b; cin >> k >>  a >> b;
        if (k == 1) st.update(a-1,b,0,n-1,1);
        else cout << st.query(a-1,b-1,0,n-1,1) << endl;
    }
 
 
    return 0;
}
