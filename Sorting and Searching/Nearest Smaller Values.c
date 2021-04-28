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
#include <queue>
 
 
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
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> ans(n);
    vector<pii> stack;
    for(int i = 0; i < n; i++) {
        while(stack.size() > 0 && stack.back().first >= v[i]) {
            stack.pop_back();
        }
        if(stack.size() == 0) {
            ans[i] = 0;
        }
        else {
            ans[i] = stack.back().second + 1;
        }
        stack.push_back({v[i], i});
    }
 
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
 
 
    return 0;
}
