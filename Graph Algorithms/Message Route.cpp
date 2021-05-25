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



int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;


    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>  pre(n, -1);
    pre[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(pre[v] == -1) {
                pre[v] = u;
                q.push(v);
            }
        }
    }
    if(pre[n - 1] == -1) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        vector<int> path = {n-1};
        int at = n - 1;
        while(at != 0) {
            path.push_back(pre[at]);
            at = pre[at];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for(int u : path) {
            cout << u + 1 << " ";
        }
        cout << endl;
    }

#ifdef MYPC
    cout << endl <<  "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms" << endl;
#endif

    return 0;
}
