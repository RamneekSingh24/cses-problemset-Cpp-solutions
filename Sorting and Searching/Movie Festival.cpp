#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

typedef pair<int, int> pii;

class CustomPairComp{
public:
    bool operator() (const pii &p1, const pii &p2) {
        return p1.second <= p2.second;
    }
}; // Gives TLE


int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif



    int n;
    cin >> n;
    vector<pii> events(n);

    for(int i = 0; i < n; i++) {
        cin >> events[i].second >> events[i].first;
    }

    sort(events.begin(), events.end());

    int cnt = 0;
    int last_dep = 0;

    for(pii event : events) {
        if(event.second >= last_dep) {
            ++cnt;
            last_dep = event.first;
        }
    }

    cout << cnt << endl;

    return 0;
}


