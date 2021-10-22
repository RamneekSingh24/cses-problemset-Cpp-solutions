#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace  std;
 
#define ll long long
#define ull unsigned long long
#define f first
#define s second
typedef pair<int , int > pii;
typedef pair<ll,ll> pll;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// erase,insert same as normal set
 
const ll MOD = 1e9+7;
 
 
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
///--//
vector<vector<int>> adj;
vector<int> parent;
vector<int> col;
int cycle_start;
int cycle_end;
void print(){
    vector<int> path;
    int tmp=cycle_start;
    path.push_back(cycle_start);
    while(tmp != cycle_end){
        tmp=parent[tmp];
        path.push_back(tmp);
    }
    reverse(path.begin(),path.end());
    path.push_back(cycle_end);
    cout<<path.size()<<endl;
    for(int i=0; i<path.size(); i++){
        cout<<path[i]+1<<" ";
    }
    exit(0);
}
void dfs(int u){
    col[u]=1;
    for(int v : adj[u]){
        if( col[v] == 2) continue;
        else if( col[v] == 0) {
            parent[v]=u;
            dfs(v);
        }
        else{
            cycle_start=u;
            cycle_end=v;
            print();
        }
    }
    col[u]=2;
}
int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    /* KEEP IN MIND
     * take care when sorting a 1 based indexed vector
     * const int N is defined way above in the starting
    */
    int n,m; cin>>n>>m;
    adj.resize(n);
    parent.resize(n);
    col.resize(n,0);
    vector<int> nodes_to_zero;
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        --u; --v;
        adj[u].push_back(v);
    }
    for(int i=0; i<n; i++){
        if(!col[i]) dfs(i);
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
