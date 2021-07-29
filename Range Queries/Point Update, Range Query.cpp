#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
class BIT {
public:
    int n;
    vector<ll> v;
 
    BIT(int n,vector<ll> vec) {
        v.assign(n+1,0);
        this->n = n+1;
        for (int i = 1; i <= n; i++) {
            this->update(vec[i-1],i);
        }
    }
    ll sum(int idx) {
        ll s = 0;
        while(idx) {
            s += v[idx];
            idx -= idx & (-idx);
        }
        return s;
    }
    ll sum(int a, int b) {
        return sum(b) - sum(a-1);
    }
    void update(int x, int p, int upd = 1) {
        if (upd == 1) {
            int val = sum(p) - sum(p-1);
            x -= val;
        }
        while(p <= n) {
            v[p] += x;
            p += p & (-p);
        }
    }
 
};
 
 
int main () {
 
    int n; cin >> n;
    int q; cin >> q;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    BIT bit(n, vec);
 
    while (q--) {
        int k,a,b; cin >> k >> a >> b;
        if(k == 1) {
            bit.update(b,a);
        }
        else {
            cout << bit.sum(a,b) << endl;
        }
    }
 
    return 0;
}
