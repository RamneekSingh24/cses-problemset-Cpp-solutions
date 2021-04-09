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

typedef pair<int, int> pii;

int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    int n;
    cin >> n;
    vector<int> vl(n), vr(n);
    vector<pair<pii, int>> events; // Event Time,  -Other Time , index
    vector<int> ans1(n, 0);
    vector<int> ans2(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> vl[i] >> vr[i];
        events.push_back({{vr[i], -vl[i]}, i});
        events.push_back({{vl[i], -vr[i]}, i});
    }
    sort(events.begin(), events.end());

    multiset<int> active_events; // start_time of active events
    for(auto e : events) {
        int t1 = e.first.first, t2 = -e.first.second, idx = e.second;

        if(t1 < t2) {
            // Start Event
            active_events.insert(t1);
        }
        else{
            // End Event
            int start_time = t2;
            active_events.erase(active_events.find(start_time));
            if(active_events.size() > 0 && *active_events.begin() <= start_time ) {
                ans2[idx] = 1;
            }
        }
    }

    set<int> closed_events; // start_time of closed events
    for(auto e : events) {
        int t1 = e.first.first, t2 = -e.first.second, idx = e.second;
        if(t1 > t2) {
            // End Event
            if (closed_events.lower_bound(t2) != closed_events.end()) {
                ans1[idx] = 1;
            }
            closed_events.insert(t2);
        }

    }

    for(int i = 0; i < n; i++) {
        cout << ans1[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << ans2[i] << " ";
    }
    cout << endl;




    return 0;
}




