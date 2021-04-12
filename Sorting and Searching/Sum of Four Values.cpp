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

    set<pii> sums; // sum(v[i1], v[i2]) , min(i1, i2)

    int n,x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            sums.insert({v[i] + v[j], i});
        }
    }

    for(int idx1 = 0; idx1 < n; idx1++) {
        for(int i = idx1 + 1; i < n; i++) {
            sums.erase({v[idx1] + v[i], idx1});
        }
        for(int idx2 = idx1 + 1; idx2 < n; idx2++) {
            int req_sum = x - v[idx1] - v[idx2];
            auto it = sums.upper_bound({req_sum, idx2});
            if(it != sums.end() && it->first == req_sum) {
                // Found ans
                int idx3 = it->second;
                req_sum -= v[idx3];

                for(int idx4 = idx3; idx4 < n; idx4++) {
                    if( idx4 == idx1 || idx4 == idx2 || idx4 == idx3) {
                        continue;
                    }
                    if( v[idx4] == req_sum) {
                        cout << idx1 + 1 << " " << idx2 + 1 << " " << idx3 + 1<< " " << idx4 + 1<< endl;
                        return 0;
                    }

                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;


    return 0;
}






