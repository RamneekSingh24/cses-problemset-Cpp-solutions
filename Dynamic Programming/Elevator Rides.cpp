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




int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;


    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<pair<int, int>> dp(1 << n);

    dp[0] = {1, 0};

    for(int msk = 1; msk < (1 << n); msk++) {
        dp[msk] = {n,x};
        for(int bit = 0; bit < n; bit++) {
            if(msk & (1 << bit)) {
                pair<int, int> so_far = dp[msk ^ (1 << bit)];
                if(so_far.second + v[bit] > x) {
                    so_far.first++;
                    so_far.second = min(so_far.second, v[bit]);
                }
                else {
                    so_far.second = so_far.second + v[bit];
                }
                dp[msk] = min(dp[msk], so_far);
            }
        }
    }

    cout << dp[(1 << n) - 1].first << endl;




    return 0;
}





