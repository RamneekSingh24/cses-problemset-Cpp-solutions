#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;


vector<int> curr_path;
vector<vector<int>> paths;

bool taken[7][7];
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const char dch[4] = {'D', 'R', 'U', 'L'};

void init() {
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 7; j++) {
            taken[i][j] = false;
        }
    }
}

bool can_go(int x, int y) {
    if(x < 0 || y < 0 || x > 6 || y > 6) {
        return false;
    }
    if(x == 6 && y == 0) {
        return curr_path.size() == 47;
    }
    return !taken[x][y];
}

bool can_go1(int x, int y) {
    // Used in checking no of unvisited neighbours including (6,0)
    if(x < 0 || y < 0 || x > 6 || y > 6) {
        return false;
    }
    return !taken[x][y];
}

bool is_critical(int x, int y) {
    int c = 0;

    for(int i = 0; i < 4; i++) {
        if(can_go1(x + dx[i], y + dy[i]) ) {
            ++c;
        }
    }
    return c == 1;
}


void find_paths(int cx, int cy) {

    if(cx == 6 && cy == 0) {
        paths.push_back(curr_path);
        return;
    }
    taken[cx][cy] = true;

    int critc_cnt = 0;
    vector<int> possible_dirs;
    int critc_dir = 0;

    for(int i = 0; i < 4; i++) {
        int nx = cx + dx[i], ny = cy + dy[i];
        if(can_go(nx, ny)) {
            if(is_critical(nx, ny)) {
                ++critc_cnt;
                critc_dir = i;
            }

            possible_dirs.push_back(i);
        }
    }

    if(possible_dirs.size() == 0 || critc_cnt > 1) {
        taken[cx][cy] = false;
        return;
    }
    if(critc_cnt == 1) {
        curr_path.push_back(critc_dir);
        find_paths(cx + dx[critc_dir], cy + dy[critc_dir]);
        curr_path.pop_back();
    }
    else {
        for(int dir : possible_dirs) {
            curr_path.push_back(dir);
            find_paths(cx + dx[dir], cy + dy[dir]);
            curr_path.pop_back();
        }
    }

    taken[cx][cy] = false;

}

string given_path;
vector<int> indices_to_check;

bool check(vector<int> path) {
    for(int ind : indices_to_check) {
        if(given_path[ind] != dch[path[ind]]) {
            return false;
        }
    }
    return true;
}
int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    init();
    find_paths(0,0);
    cin >> given_path;
    for(int i = 0; i < 48; i++) {
        if(given_path[i] != '?') {
            indices_to_check.push_back(i);
        }
    }
    int cnt = 0;
    for(auto path : paths) {
        cnt += check(path);
    }

    cout << cnt << endl;
    return 0;
}


