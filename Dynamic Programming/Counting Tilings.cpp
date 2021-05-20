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

inline vector<int> is_valid(int mask, int num_bits) {

    int c = 0;
    vector<int> vec;

    for(int i = 0; i < num_bits; i++) {
        int r = mask % 3;
        mask /= 3;
        if(r == 0) {
            ++c;
        }
        else if(c % 2 != 0) {
            return vector<int>(0);
        }
        vec.push_back(r);
    }

    if(c % 2 != 0) {
        return vector<int>(0);
    }
    else {
        return vec;
    }
}

inline bool check(vector<int> &up, vector<int> &low) {
    for(int i = 0; i < up.size(); i++) {
        if(up[i] == 0) {
            if(low[i] == 2) {
                return false;
            }
        }
        else if(up[i] == 1) {
            if(low[i] != 2) {
                return false;
            }
        }
        else {
            if(low[i] == 2) {
                return false;
            }
        }
    }
    return true;
}

const int MOD = 1e9 + 7;

int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;


    int n, m;
    cin >> n >> m;
    int pow3n = 1;
    for(int i = 1; i <= n; i++) {
        pow3n *= 3;
    }

    vector<vector<int>> all_valid;
    vector<int> all_valid_msks;

    for(int i = 0; i < pow3n; i++) {
        vector<int> vec = is_valid(i, n);
        if(vec.size() != 0) {
            all_valid.push_back(vec);
            all_valid_msks.push_back(i);
        }
    }

    vector<vector<int>> valid_complements(all_valid.size());

    for(int i = 0; i < all_valid.size(); i++) {
        for(int j = 0; j < all_valid.size(); j++) {
            if(check(all_valid[i], all_valid[j])) {
                valid_complements[i].push_back(j);
            }
        }
    }

    vector<vector<int>> dp(m+1, vector<int>(all_valid.size(), 0));

    for(int i = 0; i < all_valid.size(); i++) {
        bool f = true;
        for(int j = 0; j < n; j++) {
            if(all_valid[i][j] == 1) {
                f = false;
                break;
            }
        }
        dp[1][i] = f;
    }

    for(int col = 2; col <= m; col++) {
        for(int i = 0; i < all_valid.size(); i++) {
            for(int j : valid_complements[i]) {
                dp[col][i] += dp[col-1][j];
                if(dp[col][i] >= MOD) {
                    dp[col][i] -= MOD;
                }
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < all_valid.size(); i++) {
        bool f = true;
        for(int j = 0; j < n; j++) {
            if(all_valid[i][j] == 2) {
                f = false;
            }
        }
        if(f) {
            ans += dp[m][i];
            if(ans >= MOD) {
                ans -= MOD;
            }
        }
    }

    cout << ans << endl;

    return 0;
}





