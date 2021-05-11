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
const int MXN = 510;
int num_ways[MXN * MXN] = {0};


int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    int n;
    cin >> n;

    if(n % 4 == 1 || n % 4 == 2) {
        cout << 0 << endl;
        return 0;
    }

    num_ways[0] = 1;
    int HALF_SUM = (n * (n + 1)) / 4;

    for(int i = 1; i <= n; i++) {
        for(int x = HALF_SUM; x >= i; x--) {
            num_ways[x] += num_ways[x - i];
            if(num_ways[x] >= MOD) {
                num_ways[x] -= MOD;
            }
        }
    }

    int MOD_INV2 = 500000004;
    cout <<  (num_ways[HALF_SUM] * 1ll * MOD_INV2) % MOD  << endl;



    return 0;
}





