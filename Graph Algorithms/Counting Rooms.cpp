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

using namespace std;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

const int N = 1000;
bool vis[N][N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

inline bool can_go(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    return !vis[x][y];
}

void dfs(int x, int y) {
    vis[x][y] = true;
    for(int i = 0; i < 4; i++) {
        if(can_go(x + dx[i], y + dy[i])) {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}


int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '#') {
                vis[i][j] = true;
            }
            else {
                vis[i][j] = false;
            }
        }
    }

    int cc = 0;

    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            if(!vis[r][c]) {
                ++cc;
                dfs(r, c);
            }
        }
    }

    cout << cc << endl;



#ifdef MYPC
    cout << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#endif

    return 0;
}





