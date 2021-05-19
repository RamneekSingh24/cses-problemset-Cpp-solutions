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




int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;


    int n;
    cin >> n;
    vector<int> a(n), b(n), p(n);
    vector<pair<int ,int>> events;

    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> p[i];
        events.push_back({b[i], i});
    }

    sort(events.begin(), events.end());
    map<int, long long, greater<int>> dp;

    long long mx_so_far = 0;

    for(auto e : events) {
        int end_time = e.first, id = e.second,
            st_time = a[id], money = p[id];

        auto itr = dp.upper_bound(st_time);
        if(itr == dp.end()) {
            mx_so_far = max(mx_so_far, 0ll + money);
        }
        else {
            mx_so_far = max(mx_so_far, itr->second + money);
        }
        dp[end_time] = mx_so_far;
    }

    cout << mx_so_far << endl;


    return 0;
}





