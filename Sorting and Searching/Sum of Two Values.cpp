#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

typedef pair<int, int> pii;

class CustomPairComp{
public:
    bool operator() (const pii &p1, const pii &p2) {
        return p1.second <= p2.second;
    }
};
int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif



    int n, x;
    cin >> n >> x;
    vector<pii> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i+1;
    }
    sort(v.begin(), v.end());
    int idx1 = 0, idx2 = n-1;

    while(idx1 < idx2 && v[idx1].first + v[idx2].first != x) {

        if(v[idx1].first + v[idx2].first > x) {
            idx2--;
        }
        else {
            idx1++;
        }
    }
    if(idx1 != idx2) {
        cout << v[idx1].second << " " << v[idx2].second << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }


    return 0;
}


