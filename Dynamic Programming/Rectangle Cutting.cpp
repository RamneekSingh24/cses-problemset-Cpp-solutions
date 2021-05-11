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
const int INF = 1e9;

int dp[510][510];

int minMoves(int a, int b) {

    if(dp[a][b] != -1) {
        return dp[a][b];
    }
    if(a == b) {
        return dp[a][b] = 0;
    }
    int ans = INF;
    for(int i = 1; i <= a/2; i++) {
        ans = min(ans, 1 + minMoves(a - i, b) + minMoves(i, b));
    }
    for(int i = 1; i <= b/2; i++) {
        ans = min(ans, 1 + minMoves(a , b - i) + minMoves(a, i));
    }

    return dp[a][b] = ans;

}

int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    for(int i = 0; i < 510; i++) {
        for(int j = 0; j < 510; j++) {
            dp[i][j] = -1;
        }
    }


    int a, b;
    cin >> a >> b;
    cout << minMoves(a, b);

    return 0;
}





