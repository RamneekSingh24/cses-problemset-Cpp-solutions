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



int FindMinimumDifference(int *arr, int n) {
    vector<int> possible_sums;
    int half = (n % 2 == 0)? n /2 : (n + 1) / 2;
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    int INF = 1e7;
    map<int,map<int,map<int,int>>> dp;
    function<int(int,int,int)> calc = [&] (int pos, int taken, int cs) {
        if (pos >= n && taken < half) return INF;
        else if(taken == half) {
            possible_sums.push_back(cs);
        }
        else {
            calc(pos + 1, taken + 1, cs + arr[pos]);
            calc(pos + 1, taken, cs);
        }
        return 0;
    };
    calc(0,0,0);
    int ans = 1e9;
    for (int x : possible_sums) ans = min(ans, abs(total - x - x));
    return ans;
}

 int MAXN = 1e6 + 10;




int  main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef MYPC
    freopen("input.txt", "r", stdin);
#endif

    register_t MOD1 = 1e9 + 7;
    register_t MOD2 = 1e9 + 9; // TLE

    // COMPILER OP WITH CONST VARIABLE OPTIMIZATIONS
    


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
    ph1[0] = s[0] - 'a' + 1;
    ph2[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.length(); i++) {
        ph1[i] = (ph1[i-1] + (s[i] - 'a' + 1) * p1[i]) % MOD1;
        ph2[i] = (ph2[i-1] + (s[i] - 'a' + 1) * p2[i]) % MOD2;
        //cout << ph1[i] << " " << ph2[i] << " HI" << endl;
    }

    function<pair<ll,ll>(int,int)> hash = [&] (int l , int r) {
        if(l == 0) return make_pair(ph1[r],ph2[r]);
        else {
            ll h1 = ((ph1[r] - ph1[l-1] + MOD1) * invp1[l] ) % MOD1;
            ll h2 = ((ph2[r] - ph2[l-1] + MOD2) * invp2[l] ) % MOD2;
            return make_pair(h1, h2);
        }
    };
    int n = s.length();
    vector<int> ans;
    for (int l = 1; l <= n-1; l++) {
        pll hp1 = hash(0,l-1);
        int i = l;
        bool f = true;
        for (; i + l < n; i += l) {
            if (hash(i, i + l-1) != hp1) {
                f = false;
                break;
            }
        }
        if (f) {
            if (i <= n-1) {
                int len = n-i;

                if (hash(0,len-1) == hash(i, i + len-1)) ans.push_back(l);
            }
        }
    }

    ans.push_back(n);
    for(int x : ans) cout << x << " ";








    return 0;
}
