#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
class BIT {
public:
    int n;
    vector<ll> b1, b2;
    BIT(int n) {
        this->n = n + 2;
        b1.assign(n+2, 0);
        b2.assign(n+2, 0);
    }
 
    void add(int b, int idx, ll val) {
        if (b == 1) {
            while(idx < n) {
                b1[idx] += val;
                idx += idx & -idx;
            }
        }
        else {
            while (idx < n) {
                b2[idx] += val;
                idx += idx & -idx;
            }
        }
    }
 
    void range_add (int l, int r, ll val) {
        this->add(1,l,val);
        this->add(1,r+1,-val);
        this->add(2,l, (l-1) * val);
        this->add(2,r + 1, -r * val);
    }
 
    ll sum(int b, int p) {
        ll s = 0;
        if (b == 1) {
            while (p) {
                s += b1[p];
                p -= p & -p;
            }
        }
        else {
            while(p) {
                s += b2[p];
                p -= p & -p;
            }
        }
        return s;
    }
    ll pref_sum(int idx) {
        return sum(1, idx) * idx - sum(2, idx);
    }
    ll range_sum(int l, int r) {
        return pref_sum(r) - pref_sum(l-1);
    }
 
};
 
int main () {
 
    int n,q; cin >> n >> q;
 
    BIT bit(n);
 
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        bit.range_add(i,i,x);
    }
    while(q--) {
        int k; cin >> k;
        if (k == 1) {
            int a,b,x; cin >> a >> b >> x;
            bit.range_add(a,b,x);
        }
        else {
            int p; cin >> p;
            cout << bit.range_sum(p,p) << endl;
        }
    }
 
    return 0;
}
