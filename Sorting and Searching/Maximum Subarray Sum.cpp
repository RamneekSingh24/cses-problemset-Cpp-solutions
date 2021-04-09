#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;


int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long curr_sum = 0;
    long long ans = -1e18;

    for(int i = 0; i < n; i++) {
        curr_sum += a[i];
        ans = max(ans, curr_sum);
        if(curr_sum < 0) {
            curr_sum = 0;
        }
    }

    cout << ans << endl;

    return 0;
}


