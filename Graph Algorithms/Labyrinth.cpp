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
 
const int N = 1000;
bool vis[N][N];
pair<int, int> pre[N][N];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const map<pair<int, int>, char> dirs = {
        make_pair(make_pair(-1, 0), 'U'),
        make_pair(make_pair(0, 1), 'R'),
        make_pair(make_pair(1, 0), 'D'),
        make_pair(make_pair(0, -1), 'L'),
};
 
int n, m;
 
inline bool can_go(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    return !vis[x][y];
}
 
 
int main() {
 
#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
 
    fast_io;
 
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            pre[i][j] = {-1, -1};
        }
    }
 
    cin >> n >> m;
    pair<int, int> start, en;
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
            if(s[j] == 'A') {
                vis[i][j] = false;
                start = {i, j};
            }
            if(s[j] == 'B') {
                vis[i][j] = false;
                en = {i, j};
            }
        }
    }
 
 
    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = true;
    bool found = false;
 
    while(!q.empty()) {
        if(found) {
            break;
        }
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first, y= p.second;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(can_go(nx, ny)) {
                q.push({nx, ny});
                vis[nx][ny] = true;
                pre[nx][ny] = {x, y};
                if(nx == en.first && ny == en.second) {
                    found = true;
                }
            }
        }
    }
 
    if(!found) {
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        vector<char> path;
        pair<int, int> at = en;
        while(at.first != start.first || at.second != start.second) {
            pair<int ,int> prev = pre[at.first][at.second];
            path.push_back(dirs.find(make_pair(at.first - prev.first, at.second - prev.second))->second);
            at = prev;
        }
        cout << path.size() << endl;
        reverse(path.begin(), path.end());
        for(char d : path) {
            cout << d;
        }
    }
 
#ifdef MYPC
    cout << endl <<  "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms" << endl;
#endif
 
    return 0;
}
