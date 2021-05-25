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

    vector<int>  col(n, -1);
    bool FLAG = true;

    for(int i = 0; i < n; i++) {
        if(col[i] != -1) continue;
        col[i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (col[v] == -1) {
                    col[v] = col[u] ^ 1;
                    q.push(v);
                } else if (col[v] == col[u]) {
                    FLAG = false;
                }
            }
        }
    }

    if(FLAG) {
        for(int i = 0; i < n; i++) {
            cout << col[i] + 1 << " ";
        }
        cout << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }


#ifdef MYPC
    cout << endl <<  "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms" << endl;
#endif

    return 0;
}
