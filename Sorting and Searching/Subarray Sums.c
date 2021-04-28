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
    long long x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0 ; i < n; i++) {
        cin >> v[i];
    }
    map<long long, int> pref_sums;
    pref_sums[0] = 1;
    long long curr = 0;
    long long ans = 0;
    for(int i = 0 ; i < n; i++) {
        curr += v[i];
        ans += pref_sums[curr-x];
        pref_sums[curr]++;
    }
    cout << ans << endl;
 
 
    return 0;
}
