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

    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int best_left_idx = 0;
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        cnt[v[i]]++;
        while(cnt.size() > k) {
            int val = v[best_left_idx++];
            cnt[val]--;
            if(cnt[val] == 0) {
                cnt.erase(val);
            }
        }
        ans += (i - best_left_idx + 1);
    }

    cout << ans << endl;


    return 0;
}





