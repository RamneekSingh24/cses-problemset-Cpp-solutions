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

typedef pair<int,int> pii;

int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n+1);
    for(int i = 1 ; i <= n; i++) {
        cin >> v[i];
    }
    int ax = 0, bx = 0;
    long long sum_ax = 0 , sum_bx = 0;
    v[0] = 0;
    multiset<long long> pref_sums;
    long long ans = -1e15;
    long long curr_sum = 0;
    for(int i = 1; i <= n; i++) {
        curr_sum += v[i];
        if(i - ax >=a) {
            sum_ax += v[ax++];
            pref_sums.insert(sum_ax);
        }
        if(i - bx > b) {
            sum_bx += v[bx++];
            pref_sums.erase(pref_sums.find(sum_bx));
        }
        if(pref_sums.size() > 0) {
            ans = max(ans, curr_sum - *pref_sums.begin());
        }
    }
    cout << ans << endl;

    
    return 0;
}





