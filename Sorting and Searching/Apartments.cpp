#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;



int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    int n, m, k; cin >> n >> m >> k;

    vector<int> a(n),b(m);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    int cnt = 0;

    int idx = 0;

    for(int i = 0; i < m; i++) {
        if(idx == n) break;

        if(b[i] > a[idx] + k) {
            continue;
        }
        if(b[i] >= a[idx] - k) {
            ++cnt;
            ++idx;
        }
        else {
            ++idx;
            --i;
        }
    }

    cout << cnt << endl;




    return 0;
}


