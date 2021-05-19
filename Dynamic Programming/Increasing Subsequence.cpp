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



inline int lower_bound(const vector<int> &sorted_vec, int x) {
    int l = 0, r = sorted_vec.size()-1;
    while(l < r) {
        int md = (l + r) / 2;
        if(sorted_vec[md] >= x) {
            r = md;
        }
        else {
            l = md + 1;
        }
    }
    return l;
}


int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    int n; cin >> n;

    vector<int> v(n);
    for(int i = 0 ; i < n; i++) {
        cin >> v[i];
    }

    int INF = 1e9 + 10;
    vector<int> lens(n+1, INF);


    for(int i = 0; i < n; i++) {
        int idx = lower_bound(lens, v[i]);
        lens[idx] = min(lens[idx], v[i]);
    }

    int ans = 1;
    for(int i = n-1; i >= 0; i--) {
        if(lens[i] < INF) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;


    return 0;
}





