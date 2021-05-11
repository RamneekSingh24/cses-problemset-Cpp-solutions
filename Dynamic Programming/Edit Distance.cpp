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


string s1,s2;
int dp[5010][5010];

int editDistance(int idx1, int idx2) {

    if(dp[idx1][idx2] != -1) {
        return dp[idx1][idx2];
    }

    if(idx2 == s2.length()) {
        return dp[idx1][idx2] = s1.length() - idx1;
    }

    if(idx1 == s1.length()) {
        return dp[idx1][idx2] = s2.length() - idx2;
    }

    if(s1[idx1] == s2[idx2]) {
        return dp[idx1][idx2] = editDistance(idx1 + 1, idx2 + 1);
    }

    return dp[idx1][idx2] = min({
        1 + editDistance(idx1, idx2 + 1),
        1 + editDistance(idx1 + 1, idx2),
        1 + editDistance(idx1 + 1 , idx2 + 1)
    });

}


int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    for(int i = 0; i < 5010; i++) {
        for(int j = 0; j < 5010; j++) {
            dp[i][j] = -1;
        }
    }

    cin >> s1 >> s2;

    cout << editDistance(0, 0);

    return 0;
}





