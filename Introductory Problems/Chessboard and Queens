#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;


bool board[8][8];
int blocked[8][8];
int cnt = 0;
int dx[4] = {1, 0, 1, -1};
int dy[4] = {0, 1, 1, 1};

bool inside_board(int x, int y) {
    if(x < 0 || y < 0 || y > 7 || x > 7) {
        return false;
    }
    return true;
}

void place_queen(int x, int y) {

    blocked[x][y]++;
    for(int i = 0; i < 4; i++) {
        for(int dir : {1, -1}) {
            int tx = x, ty = y;

            while(inside_board(tx, ty)) {
                if(!(tx == x && ty == y)) {
                    blocked[tx][ty]++;
                }
                tx += dx[i] * dir;
                ty += dy[i] * dir;
            }
        }
    }

}

void remove_queen(int x, int y) {
        blocked[x][y]--;
        for(int i = 0; i < 4; i++) {
            for(int dir : {1, -1}) {
                int tx = x, ty = y;

                while(inside_board(tx, ty)) {
                    if(!(tx == x && ty == y)) {
                        blocked[tx][ty]--;
                    }
                    tx += dx[i] * dir;
                    ty += dy[i] * dir;
                }
            }
        }
}


void generate(int num_queens = 8, int lx = -1, int ly = -1) {
    if(num_queens == 0) {
        ++cnt;
        return;
    }
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(i < lx || (i == lx && j <= ly)) {
                continue;
            }
            if(board[i][j] && blocked[i][j] == 0) {
                place_queen(i, j);
                generate(num_queens - 1, i, j);
                remove_queen(i, j);
            }
        }
    }

}

int main() {

    #ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    for(int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < 8; j++) {
            if(s[j] == '*') {
                board[i][j] = false;
            }
            else {
                board[i][j] = true;
            }
            blocked[i][j] = 0;
        }
    }

    generate();

    cout << cnt << endl;



    return 0;
}
