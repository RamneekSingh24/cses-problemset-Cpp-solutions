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


    int n, m;
    cin >> n >> m;
    vector<int> vals(n);
    for(int i = 0 ; i < n; i++) {
        cin >> vals[i];
    }

    vector<int> dp(m+2, 0);
    if(vals[0] == 0) {
        for(int i = 1; i <= m; i++) {
            dp[i] = 1;
        }
    }
    else {
        dp[vals[0]] = 1;
    }

    for(int i = 1; i < n; i++) {
        vector<int> newdp(m+2,0);
        if(vals[i] == 0) {
            for(int j = 1; j <= m; j++) {
                newdp[j] = dp[j-1] + dp[j+1];
                if(newdp[j] >= MOD) {
                    newdp[j] -= MOD;
                }
                newdp[j] += dp[j];
                if(newdp[j] >= MOD) {
                    newdp[j] -= MOD;
                }
            }
        }
        else {
            newdp[vals[i]] = dp[vals[i] - 1] + dp[vals[i] + 1];
            if(newdp[vals[i]] >= MOD) {
                newdp[vals[i]] -= MOD;
            }
            newdp[vals[i]] += dp[vals[i]];
            if(newdp[vals[i]] >= MOD) {
                newdp[vals[i]] -= MOD;
            }
        }
        dp = newdp;
    }


    int ans = 0;
    for(int i = 1; i <= m; i++) {
        ans += dp[i];
        if(ans >= MOD) {
            ans -= MOD;
        }
    }
    cout << ans << endl;



    return 0;
}





