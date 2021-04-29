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

    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> min_coins(x+1,1e9);
    min_coins[0] = 0;
    for(int i = 0 ; i < n; i++) {
        for(int j = v[i]; j <= x; j++) {
            min_coins[j] = min(min_coins[j], min_coins[j- v[i]] + 1);
        }
    }

    cout <<( (min_coins[x] == 1e9)? -1 : min_coins[x] )<< endl;

    return 0;
}





