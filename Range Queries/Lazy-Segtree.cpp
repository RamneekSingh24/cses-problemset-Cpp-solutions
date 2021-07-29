#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
class Segtree{
public:
    int n;
    vector<ll> lazy;
    vector<ll> t;
    vector<int> clazy;
 
    Segtree(int n) {
        this->n = n;
        lazy.assign(4*n+5, 0);
        t.assign(4*n+5,0);
        clazy.assign(4*n+5,0);
    }
 
    void prop(int v, int tl, int tr) {
        int x = clazy[v];
        if (x == 0) return;
        if (tl != tr) {
            if (x == 1) {
                if (clazy[2*v] == 0) clazy[2*v] = x;
                if (clazy[2*v+1] == 0) clazy[2*v+1] = x;
                lazy[2*v] += lazy[v];
                lazy[2*v+1] += lazy[v];
            }
            else {
                clazy[2*v] = x;
                clazy[2*v + 1] = x;
                lazy[2*v] = lazy[v];
                lazy[2*v+1] = lazy[v];
            }
        }
        if(x == 1) t[v] += (tr - tl + 1) * 1ll * lazy[v];
        else t[v] = (tr - tl + 1) * 1ll * lazy[v];
        clazy[v] = 0;
        lazy[v] = 0;
    }
 
 
    void build(vector<int> &vec, int tl, int tr, int v) {
        if (tl == tr) t[v] = vec[tl];
        else {
            int tm = (tl+tr)/2;
            build(vec,tl,tm, 2*v);
            build(vec,tm+1,tr, 2*v+1);
            t[v] = t[2*v] + t[2*v+1];
        }
    }
 
 
    void update(int tl, int tr, int v, int l, int r ,int x, int type) {
        //cout << "Updating : " << tl << " " << tr << " " << v << " " << l << " " << r << " " << x << " " << type << endl;
        if(clazy[v] > 0) prop(v, tl,tr);
        if (r < tl || l > tr) return;
        if (l <= tl && tr <= r) {
            clazy[v] = type;
            if (type == 1) lazy[v] += x;
            else lazy[v] = x;
            prop(v,tl,tr);
            return;
        }
        int tm = (tl + tr) / 2;
        update(tl,tm,2*v,l,r,x,type);
        update(tm+1,tr,2*v+1,l,r,x,type);
        t[v] = t[2*v] + t[2*v+1];
    }
 
 
    ll query(int tl, int tr, int v, int l, int r) {
        if(clazy[v] > 0) prop(v,tl,tr);
        if(r < tl || l > tr) return 0;
        if(l <= tl && tr <= r) return t[v];
        int tm = (tl+tr)/2;
        return query(tl,tm,2*v,l,r) + query(tm+1,tr,2*v+1,l,r);
    }
 
};
 
int main () {
 
    int n,q; cin >> n >> q;
 
    Segtree st(n);
    vector<int> vec(n);
 
    for (int i = 0; i < n; i++) cin >> vec[i];
    st.build(vec,0,n-1,1);
 
    while(q--) {
        int t; cin >> t;
        if (t == 1 || t == 2) {
            int a,b,x; cin >> a >> b >> x;
            st.update(0,n-1,1,a-1,b-1,x,t);
        }
        else {
            int a, b; cin >> a >> b;
            cout << st.query(0, n-1, 1, a-1,b-1) << endl;
        }
    }
 
    return 0;
}
