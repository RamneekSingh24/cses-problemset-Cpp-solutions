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

    int x, n;
    cin >> x >> n;

    set<int> lights = {0,x};
    multiset<int, greater<int>> passages = {-1,x};

    for(int i = 0; i < n; i++) {
        int p; cin >> p;
        auto it = lights.upper_bound(p);
        int next_light = *it;
        it--;
        int prev_light = *it;

        passages.erase(passages.find(next_light - prev_light ));

        passages.insert(p - prev_light);
        passages.insert(next_light - p);
        lights.insert(p);

        cout << *passages.begin() << " " << endl;

    }

    return 0;
}




