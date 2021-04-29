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

    vector<int> digits = {1};

    auto inc = [&] () {
        int sz = digits.size();
        int idx = 0;
        while(10 == ++digits[idx]) {
            digits[idx] = 0;
            if(++idx == sz) {
                digits.push_back(1);
                break;
            }
        }
    };

    int n;
    cin >> n;
    vector<int> dp(n+1, 1e9);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int d : digits) {
            dp[i] = min(dp[i], dp[i - d] + 1);
        }
        inc();
    }
    cout << dp[n] << endl;



    return 0;
}





