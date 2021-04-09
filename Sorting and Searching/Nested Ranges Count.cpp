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

// Solution gives TLE with ordered_map, Max. Execution time > 1 sec
// Solution passed with unordered_map, Max. Execution time 0.79
// On previous problems the opposite was observed.

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

typedef pair<int, int> pii;


int MAXN = 4e5 + 10;

vector<int> BIT(MAXN, 0);

void update(int idx, int add) {
    while(idx > 0 && idx < BIT.size()) {
        BIT[idx] += add;
        idx += idx & (-idx);
    }
}
int sum(int idx) {
    int ans = 0;
    while(idx > 0) {
        ans += BIT[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
void insert(int x) {
    update(x, 1);
}
void erase(int x) {
    update(x, -1);
}



int getRank(int x) {
    // Number of Elements <= x
    return sum(x);
}


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

    set<int> event_times;

    for(int i = 0; i < n; i++) {
        cin >> vl[i] >> vr[i];
        event_times.insert(vl[i]);
        event_times.insert(vr[i]);
    }

    unordered_map<int ,int> mpka; // For co-ordinate compression
    int rank = 1;
    for(int time : event_times) {
        mpka[time] = rank++;
    }

    for(int i = 0; i < n; i++) {
        int l = mpka[vl[i]], r = mpka[vr[i]];
        events.push_back({{r, -l}, i});
        events.push_back({{l, -r}, i});
    }
    sort(events.begin(), events.end());

     // BIT used for start_time of active events
    for(auto e : events) {
        int t1 = e.first.first, t2 = -e.first.second, idx = e.second;

        if(t1 < t2) {
            // Start Event
            insert(t1);
        }
        else{
            // End Event
            int start_time = t2;
            erase(t2);
            ans2[idx] = getRank(start_time); // total open events with start time <= start_time of the curr event
        }
    }

    BIT = vector<int> (MAXN, 0); // BIT for start_time of closed events
    int total_closed = 0;
    for(auto e : events) {
        int t1 = e.first.first, t2 = -e.first.second, idx = e.second;
        if(t1 > t2) {
            // End Event
            // t2 = start_time
            ans1[idx] += total_closed - sum(t2 -1); // Total Closed Events with start time >= t2
            insert(t2);
            ++total_closed;
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




