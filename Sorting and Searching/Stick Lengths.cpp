#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // STL function for k_th order statistic in average time O(n)
    nth_element(v.begin(),  v.begin() + n / 2 - 1, v.end());
    int median = v[n / 2 - 1];

    long long ans = 0;

    for(int num : v) {
        ans += abs(median - num);
    }

    cout << ans << endl;


    return 0;
}


