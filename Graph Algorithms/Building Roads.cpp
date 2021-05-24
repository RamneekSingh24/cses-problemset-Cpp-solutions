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

void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis) {
    vis[u] = true;
    for(int v : adj[u]) {
        if(!vis[v]) {
            dfs(v, adj, vis);
        }
    }
}

int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<bool> vis(n, false);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> components;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            components.push_back(i);
            dfs(i, adj, vis);
        }
    }

    cout << components.size() -1 << endl;
    for(int i = 0; i + 1 < components.size(); i++) {
        cout << components[i] + 1 << " " << components[i+1] + 1 << endl;
    }

#ifdef MYPC
    cout << endl <<  "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms" << endl;
#endif

    return 0;
}
