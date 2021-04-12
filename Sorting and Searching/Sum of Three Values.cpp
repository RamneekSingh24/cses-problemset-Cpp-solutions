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

typedef pair<int, int> pii;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

pii find(vector<pii> &v, int mx_idx, int req_sum) {
    int lx = 0, rx = mx_idx;

    while(lx < rx && v[lx].first + v[rx].first != req_sum) {
        if(v[lx].first + v[rx].first > req_sum) {
            rx--;
        }
        else {
            lx++;
        }
    }

    return {v[lx].second, v[rx].second};

}
int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    int n,x;
    cin >> n >> x;
    vector<pii> v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());


    for(int idx = n-1; idx > 1; --idx) {
        pii p = find(v, idx-1, x - v[idx].first);
        if(p.first != p.second) {
            cout << v[idx].second << " " << p.first << " " << p.second << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}




