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

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    set<pii> vals;
    long long total_sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(i < k) {
            vals.insert({v[i], i});
            total_sum += v[i];
        }
    }
    auto itr = vals.begin();
    long long lower_sum = itr->first;
    int med_pos = (k+1)/2;
    for(int i = 1 ; i < med_pos; i++) {
        itr++;
        lower_sum += itr->first;
    }

    auto cost = [&] () {
        long long c = (long long) itr->first * (med_pos) - lower_sum;
        c += total_sum-lower_sum - (long long) itr->first * (k - med_pos);
        return c;
    };

    vector<long long> ans = {cost()};

    for(int i = k ; i < n; i++) {
        vals.insert({v[i], i});
        if(make_pair(v[i], i) <= *itr) {
            lower_sum = lower_sum - itr->first + v[i];
            itr--;
        }
        if(make_pair(v[i-k], i-k) <= *itr) {
            itr++;
            lower_sum = lower_sum - v[i-k] + itr->first;
        }
        vals.erase({v[i-k], i-k});
        total_sum = total_sum + v[i] - v[i-k];
        ans.push_back(cost());
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}




