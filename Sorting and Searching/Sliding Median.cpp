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

int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    set<pii> vals;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(i < k) {
            vals.insert({v[i], i});
        }
    }
    auto itr = vals.begin();
    for(int i = 1 ; i < (k+1)/2; i++) {
        itr++;
    }
    vector<int> ans = {itr->first}; // itr points at (k+1)/2 th element from start
    for(int i = k ; i < n; i++) {
        vals.insert({v[i], i});
        if(make_pair(v[i], i) <= *itr) {
            itr--;
        }
        if(make_pair(v[i-k], i-k) <= *itr) {
            itr++;
        }
        vals.erase({v[i-k], i-k});
        ans.push_back(itr->first);
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}




