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
    vector<int> best(x+1, 0);
    vector<int> prices(n, 0), pages(n, 0);

    for(int i = 0 ; i < n; i++) {
        cin >> prices[i];
    }

    for(int i = 0 ; i < n; i++) {
        cin >> pages[i];
    }

    for(int i = 0; i < n; i++) {
        int pr = prices[i];
        int pg = pages[i];
        for(int j = x; j >= pr; j--) {
            best[j] = max(best[j], best[j - pr] + pg);
        }
    }

    cout << best[x] << endl;



    return 0;
}





