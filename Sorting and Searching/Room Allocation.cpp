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


int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    int n;
    cin >> n;

    vector<int> ans(n);
    int mx = 0;
    vector<pii> events;

    for(int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        events.push_back({a, -(i + 1)});
        events.push_back({b, i+1});
    }
    sort(events.begin(), events.end());
    vector<int> rooms;
    for(int i = n; i >= 1; i--) {
        rooms.push_back(i);
    }

    for(pii e : events) {
        int type = e.second > 0, idx = abs(e.second)-1;
        if(type == 0) {
            ans[idx] = rooms.back();
            rooms.pop_back();
            mx = max(mx, ans[idx]);
        }
        else {
            rooms.push_back(ans[idx]);
        }
    }

    cout << mx << endl;
    
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}




