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

// Solution Using Binary Search
// Be Careful With Upper Bound

using namespace std;

typedef pair<int, int> pii;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

bool can(long long t, vector<int> &machines, int num_prods) {
    long long can_make = 0;
    for(int i = 0; i < machines.size(); i++) {
        can_make += t/machines[i];
        if(can_make >= num_prods) {
            return true;
        }
    }
    return false;
}

int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    int n,k;
    cin >> n >> k;
    vector<int> machines(n);

    for(int i = 0; i < n; i++) {
        cin >> machines[i];
    }

    long long l = 1, r = 1e18 + 10;

    while(l < r) {
        long long m = (l + r) / 2;
        if(can(m, machines, k)) {
            r = m;
        }
        else {
            l = m+1;
        }
    }
    cout << l << endl;

    return 0;
}




