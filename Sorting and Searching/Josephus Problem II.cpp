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
 
const int MAXN = 2e5+10;
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
void insert(int num) {
    update(num, 1);
}
void remove(int num) {
    update(num, -1);
}
 
int getElementByRank(int rank) {
 
    int lx = 0;
    int rx = BIT.size()-1;
    while(lx < rx) {
        int mx = (rx + lx) / 2;
 
        if(sum(mx) >= rank) {
            rx = mx;
        }
        else {
            lx = mx + 1;
        }
    }
    return lx;
}
 
int getRank(int x) {
    return sum(x);
}
 
int main() {
 
#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
 
    fast_io;
 
    int n, k; cin >> n >> k;
 
    for(int i = 1; i <= n; i++) {
        insert(i);
    }
    int curr_child = 1;
 
    for(int sz = n; sz > 0; sz--) {
        int curr_idx = getRank(curr_child);
        int del_idx = 1 + (curr_idx - 1 + k) % sz;
        int next_idx = (del_idx + 1) % sz;
 
        int del_child = getElementByRank(del_idx);
        int next_child = getElementByRank(next_idx);
 
        remove(del_child);
        curr_child = next_child;
 
        cout << del_child << " ";
 
    }
 
 
    return 0;
}
 
