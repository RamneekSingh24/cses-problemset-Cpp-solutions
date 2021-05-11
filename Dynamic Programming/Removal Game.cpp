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
const long long INF = 1e18;
long long dp[5005][5005][2];
int vals[5005];

long long calc(int p, int curr, int l, int r) {

    if(dp[l][r][p] != -INF) {
        return dp[l][r][p];
    }
    if(l > r) {
        return dp[l][r][p] = 0;
    }
    if(l == r) {
        return dp[l][r][p] = vals[l] * (p == curr);
    }

    if(p == curr) {
        return dp[l][r][p] = max(
                vals[l] + calc(p, curr ^ 1, l + 1, r),
                vals[r] + calc(p, curr ^ 1, l, r - 1)
        );
    }
    else {
        long long p1 = vals[l] + calc(p ^ 1, curr ^ 1, l + 1, r);
        long long p2 = vals[r] + calc(p ^ 1, curr ^ 1, l, r-1);
        if(p1 >= p2) {
            return dp[l][r][p] = calc(p, curr ^ 1, l + 1, r);
        }
        else {
            return dp[l][r][p] = calc(p, curr ^ 1, l, r-1);
        }

    }

}


int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;


    for(int i = 0; i < 5005; i++) {
        for(int j = 0; j < 5005; j++) {
            for(int k = 0; k < 2; k++) {
                dp[i][j][k] = -INF;
            }
        }
    }

    int n ;
    cin >> n;

    for(int i = 0 ; i < n; i++) {
        cin >> vals[i];
    }

    cout << calc(0, 0, 0, n-1) << endl;
    return 0;
}





