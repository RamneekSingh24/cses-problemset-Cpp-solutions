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

long long cnt[19][10];

long long calc(long long x) {
    if(x < 0 ) {
        return 0;
    }
    if( x == 0) {
        return 1;
    }

    vector<int> digs;
    while(x) {
        digs.push_back(x % 10);
        x /= 10;
    }

    int ND = digs.size();

    long long dp[19][10] = {0};

    for(int i = 0; i <= digs[0]; i++) {
        dp[0][i] = 1;
    }

    for(int i = 1; i < ND; i++) {
        for(int d = 0; d < digs[i]; d++) {
            for(int pd = 0; pd < 10; pd++) {
                if(pd == d) continue;
                dp[i][d] += cnt[i - 1][pd];
            }
        }

        for(int pd = 0; pd < 10; pd++) {
            if(pd == digs[i]) continue;
            dp[i][digs[i]] += dp[i - 1][pd];
        }
    }


    long long ans = 0;
    for(int i = 1; i < 10; i++) {
        ans += dp[ND - 1][i];
    }
    for(int i = 0; i < ND; i++) {
        ans += cnt[i][0];
    }

    return ans;

}


int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    for(int i = 0; i < 10; i++) {
        cnt[0][i] = 1;
    }

    for(int i = 1; i < 19; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                if(k == j) continue;
                cnt[i][j] += cnt[i-1][k];
            }
        }
    }

    long long a, b;
    cin >> a >> b;
    cout << calc(b) - calc(a - 1) << endl;


#ifdef MYPC
    cout << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#endif

    return 0;
}





