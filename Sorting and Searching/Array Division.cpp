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
#include <queue>


using namespace std;

typedef pair<int, int> pii;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)


int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    int mx = 0 ;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx , v[i]);
    }

    auto is_possbile = [&] (long long sum) {
        if(sum < mx) {
            return false;
        }

        int num_sub_arrays = 1;
        long long curr_sum = 0 ;
        for(int i = 0; i < n; i++) {
            curr_sum += v[i];
            if(curr_sum > sum) {
                curr_sum = v[i];
                num_sub_arrays++;
            }
        }

        return num_sub_arrays <= k;
    };

    long long lx = 0;
    long long rx = 1e15;

    while(lx < rx) {
        long long midx = (lx + rx) / 2;
        
        if(is_possbile(midx)) {
            rx = midx;
        }
        else {
            lx = midx + 1;
        }

    }

    cout << lx << endl;

    return 0;
}





