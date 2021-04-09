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

// Unordered Map Gives TLE

int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    map<int, int> prev_pos;

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        prev_pos[v[i]] = -1;
    }

    int ans = 0;
    int c = 0;
    int sidx = 0;
    for(int i = 0; i < n; i++) {
        ++c;
        int pv_pos = prev_pos[v[i]];
        if(pv_pos >= sidx) {
            c = i - pv_pos;
            sidx = pv_pos + 1;
        }
        prev_pos[v[i]] = i;
        ans = max(ans, c);
    }

    cout << ans << endl;


    return 0;
}




