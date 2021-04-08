#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;




int main() {

    #ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    long long total_sum = 0;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i < n; i++) {
        cin >> a[i];
        total_sum += a[i];
    }
    long long ans = 1e13;

    for(int mask = 0; mask < (1 << n); mask++) {
        long long subset_sum = 0;
        for(int bit = 0; bit < n; bit++) {
            if(mask & (1 << bit)) {
                subset_sum += a[bit];
            }
        }
        ans = min(ans, abs(total_sum - 2 * subset_sum));
    }

    cout << ans << endl;

    return 0;
}
