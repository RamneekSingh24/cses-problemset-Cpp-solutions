#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <iomanip>
using namespace  std;

#define ll long long
#define ull unsigned long long
#define f first
#define s second
typedef pair<int , int > pii;
typedef pair<ll,ll> pll;


ll MOD = 1e9 + 7;


void min_self(ll &a , ll b){a=min(a,b);}
void max_self(ll &a, ll b){a=max(a,b);}
ll add(ll x, ll y){return (x + y) % MOD;}
ll sub(ll x, ll y){return add(x, MOD - y);}
ll mul(ll x, ll y){return (x * 1ll * y) % MOD;}
ll binpow(ll x, ll y)
{
    ll z = 1;
    while(y > 0)
    {
        if(y % 2 == 1)
            z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}
ll inv(ll x){return binpow(x, MOD - 2);}
const int MXN = 1e6+10;
ll fact[MXN];
void fac_pre()
{
    fact[0]=1;
    for(ll i=1; i<MXN; i++){
        fact[i]=mul(fact[i-1],i);
    }
}
ll C(ll n, ll k)
{
    return mul(fact[n], inv(mul(fact[k], fact[n - k])));
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll x, ll y) {
    return (x * y) / gcd(x,y);
}
//--//




 int MAXN = 2e6 + 10;

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;


int  main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef MYPC
    freopen("input.txt", "r", stdin);
#endif




    vector<ll> p1(MAXN), p2(MAXN), invp1(MAXN), invp2(MAXN);



    ll b = 31;


    MOD = MOD1;
    ll inv1 = inv(b);
    MOD = MOD2;
    ll inv2 = inv(b);

    p1[0] = 1, p2[0] = 1, invp1[0] = 1, invp2[0] = 1;

    for (int i = 1; i < MAXN; i++) {
        p1[i] = (b * p1[i-1]) % MOD1;
        p2[i] = (b * p2[i-1]) % MOD2;
        invp1[i] = (inv1 * invp1[i-1]) % MOD1;
        invp2[i] = (inv2 * invp2[i-1]) % MOD2;
    }

    vector<ll> ph1(MAXN), ph2(MAXN);

    string s; cin >> s;
    int n = s.length();
    s += s;

    ph1[0] = s[0] - 'a' + 1;
    ph2[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.length(); i++) {
        ph1[i] = (ph1[i-1] + (s[i] - 'a' + 1) * p1[i]) % MOD1;
        ph2[i] = (ph2[i-1] + (s[i] - 'a' + 1) * p2[i]) % MOD2;
        //cout << ph1[i] << " " << ph2[i] << " HI" << endl;
    }

    function<ll(int,int)> hash = [&] (int l , int r) {
        if(l == 0) return ph1[r];
        else {
            ll h1 = ((ph1[r] - ph1[l-1] + MOD1) * invp1[l] ) % MOD1;
            //ll h2 = ((ph2[r] - ph2[l-1] + MOD2) * invp2[l] ) % MOD2;
            return h1;
        }
    };



    // compare with hashing, nlogn with lots of mod , mp TLE
    // try with 1 MOD ??
    auto cmp = [&] (int i, int j) {
        int l = 0, r = n-1;
        while(l < r) {
            int m = (l + r)/2 + 1;
            if (hash(i, i + m -1) == hash(j, j + m-1)) l = m;
            else r = m-1;
        }
        return s[i+l] < s[j+l];
    };



    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (cmp(i, ans)) ans = i;
    }

    cout << s.substr(ans,n);




    return 0;
}
