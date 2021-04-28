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
    vector<pii> events;
    multiset<int, greater<int>> available_time;
    for(int i = 0 ; i < k; i++) {
        available_time.insert(0);
    }

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({b, a}); // (end_time, start_time)
    }
    sort(events.begin(), events.end());
    int ans = 0;
    for(pii e : events) {
        int st_time = e.second;
        auto it = available_time.lower_bound(st_time);
        if(it != available_time.end()) {
            available_time.erase(it);
            available_time.insert(e.first);
            ++ans;
        }
    }

    cout << ans << endl;



    return 0;
}





