#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

const int MAXN = 2e5 +10;

int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    long long can_create_upto = 0;

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++) {
        if(v[i] > can_create_upto + 1) {
            break;
        }
        else {
            can_create_upto += v[i];
        }
    }

    cout << can_create_upto + 1 << endl;

    return 0;
}


