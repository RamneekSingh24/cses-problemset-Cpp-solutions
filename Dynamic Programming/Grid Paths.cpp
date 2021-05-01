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

using namespace std;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;


int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            if(s[j] == '*') {
                grid[i][j] = 1;
            }
        }
    }

    auto can_go = [&] (int x, int y) {
        if(x < 0 || x >=n || y < 0 || y >= n) {
            return false;
        }
        return grid[x][y] == 0;
    };
  
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[n-1][n-1] = grid[n-1][n-1]^1;
  
    for(int i = n-1; i >=0; i--) {
        for(int j = n-1; j >=0; j--) {
            if(grid[i][j]) {
                continue;
            }
            if(can_go(i+1, j)) {
                dp[i][j] += dp[i+1][j];
            }
            if(can_go(i, j+1)) {
                dp[i][j] += dp[i][j+1];
            }
            if(dp[i][j] >= MOD) {
                dp[i][j] -= MOD;
            }
        }
    }

    cout << dp[0][0] << endl;


    return 0;
}





