#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <map>
#include <unordered_map>
#include <ctime>
#include <queue>

using namespace std;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)


vector<int> dfs_stack;

void print_cycle(int start, int end) {
    vector<int> cycle;
    while(dfs_stack.back() != start) {
        cycle.push_back(dfs_stack.back());
        dfs_stack.pop_back();
    }
    cycle.push_back(start);
    cycle.push_back(end);
    cout << cycle.size() << endl;
    for(int v : cycle) {
        cout << v + 1 << " ";
    }
    cout << endl;
    exit(0);
}


void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis, int par = -1) {

    dfs_stack.push_back(u);
    vis[u] = true;
    for(int v : adj[u]) {
        if(!vis[v]) {
            dfs(v, adj, vis, u);
        }
        else if(v != par) {
            print_cycle(v, u);
        }
    }
    dfs_stack.pop_back();
}


int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis);
        }
    }

    cout << "IMPOSSIBLE" << endl;

#ifdef MYPC
    cout << endl <<  "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms" << endl;
#endif

    return 0;
}
