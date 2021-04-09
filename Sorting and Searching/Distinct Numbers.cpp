#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

// The test-set contains adverserials test cases for cpp-default hashing function


int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    set<int> nums;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.insert(x);
    }
    cout << nums.size() << endl;

    return 0;
}


