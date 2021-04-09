#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

// Don't Forget To Use Multiset


int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    multiset<int,greater<int>> tickets;

    int n,m; cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tickets.insert(x);
    }

    for(int i = 0; i < m; i++) {
        int max_pr;
        cin >> max_pr;
        auto it = tickets.lower_bound(max_pr);
        if(it == tickets.end()) {
            cout << -1 << endl;
        }
        else {
            cout << *it << endl;
            tickets.erase(it);
        }
    }




    return 0;
}


