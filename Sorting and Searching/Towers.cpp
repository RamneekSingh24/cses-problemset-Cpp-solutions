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
 
    multiset<int> top_cubes;
    int n;
    cin >> n;
    while(n--) {
        int k;
        cin >> k;
        auto it = top_cubes.upper_bound(k);
        if(it != top_cubes.end()) {
            top_cubes.erase(it);
        }
        top_cubes.insert(k);
    }
    cout << top_cubes.size() << endl;
    return 0;
}
