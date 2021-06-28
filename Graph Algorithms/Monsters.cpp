#include <iostream>
#include <algorithm>
#include <vector>

using namespace  std;

#define ll long long
#define ull unsigned long long
#define f first
#define s second
typedef pair<int , int > pii;
typedef pair<ll,ll> pll;


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
int n,m;
vector<vector<bool>> blocked;
bool can_go(int i,int j){
    if( i<0 || i>=n) return false;
    if( j<0 || j>=m) return false;
    return !blocked[i][j];
}
vector<pii> get_adj(pii u){
    vector<pii> v;
    int i=u.first;
    int j=u.second;
    v.push_back({i+1,j}); v.push_back({i-1,j}); v.push_back({i,j+1});v.push_back({i,j-1});
    return v;
}
void print_dir(pii from , pii to){
    int i1=from.first; int j1=from.second;
    int i2=to.first; int j2=to.second;
    if( i2 - i1 == 1) cout<<'D';
    if( i1 - i2 == 1) cout<<'U';
    if( j2 - j1 == 1) cout<<'R';
    if( j1 - j2 == 1) cout<<'L';
}
int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef MYPC
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    blocked.resize(n, vector<bool>(m, false));
    pii start;
    vector<pii> monster_positions;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '#') blocked[i][j] = true;
            if( s[j] == 'M') {
                monster_positions.push_back({i,j});
                blocked[i][j] = true;
            }
            if (s[j] == 'A') start = {i, j};
        }
    }
    vector<vector<pii>> parent(n, vector<pii>(m, {-1, -1}));
    vector<pii> curr_layer;
    curr_layer.push_back(start);
    parent[start.first][start.second] = start;
    blocked[start.first][start.second] = true;
    bool found=false;
    pii end;
    while (curr_layer.size() != 0) {
        vector<pii> new_monster_positions;
        for( pii pos : monster_positions){
            vector<pii> adj=get_adj(pos);
            for( auto v : adj ){
                if( can_go(v.first,v.second)){
                    blocked[v.first][v.second]=true;
                    new_monster_positions.push_back(v);
                }
            }
        }
        vector<pii> next_layer;
        for( pii u : curr_layer) {
            if( u.first == 0 || u.first == n-1 || u.second == 0 || u.second == m-1){
                found=true;
                end=u;
            }
            vector<pii> adj = get_adj(u);
            for (pii v : adj) {
                if (can_go(v.first, v.second)) {
                    next_layer.push_back(v);
                    parent[v.first][v.second] = u;
                    blocked[v.first][v.second] = true;
                }
            }
        }
        monster_positions=new_monster_positions;
        curr_layer=next_layer;
    }
    if(!found) {
        cout << "NO" << endl;
        return 0;
    }
    cout<<"YES"<<endl;
    vector<pii> path;
    path.push_back(end);
    pii x=end;
    while(x != start){
        x=parent[x.first][x.second];
        path.push_back(x);
    }
    reverse(path.begin(),path.end());
    cout<<path.size()-1<<endl;
    for(int i=0; i+1<path.size() ;i++){
        print_dir(path[i],path[i+1]);
    }

    return 0;
}
