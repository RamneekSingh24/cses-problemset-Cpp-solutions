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

void add(int &a, int b) {
    a += b;
    if(a >= MOD) {
        a -= MOD;
    }
}

int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    int sz = 1e6+10;
    vector<int> dp1(sz, 0);  // ending with vertical blocks
    vector<int> dp2(sz, 0);  // ending with horizontal blocks

    dp1[1] = 1;
    dp2[1] = 1;

    int sumdp = 2;

    for(int i = 2; i < sz; i++) {
        dp2[i] = 1;
        add(dp1[i], dp1[i-1]);
        add(dp1[i], dp1[i-1]);
        add(dp1[i], dp1[i-1]);
        add(dp1[i], dp1[i-1]);
        add(dp1[i], dp2[i-1]);
        add(dp2[i], sumdp);
        add(sumdp, dp1[i]);
        add(sumdp, dp2[i]);
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << (dp1[n] + dp2[n]) % MOD << endl;
    }


    return 0;
}





