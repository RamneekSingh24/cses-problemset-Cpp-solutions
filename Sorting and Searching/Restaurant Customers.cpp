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

int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    vector<pii> events;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int arr, dep;
        cin >> arr >> dep;
        events.push_back({arr, 0});
        events.push_back({dep, 1});
    }
    sort(events.begin(), events.end());

    int ans = 0;
    int c = 0;

    for(pii event : events) {
        if(event.second == 0) {
            ++c;
            ans = max(ans, c);
        }
        else {
            --c;
        }
    }

    cout << ans << endl;


    return 0;
}


