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

typedef pair<int, int> pii;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

bool can(long long t, vector<int> &machines, int num_prods) {
    long long can_make = 0;
    for(int i = 0; i < machines.size(); i++) {
        can_make += t/machines[i];
        if(can_make >= num_prods) {
            return true;
        }
    }
    return false;
}

int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fast_io;

    int n;
    cin >> n;

    long long ans = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        int d;
        cin >> a[i] >> d;
        ans += d;
    }
    sort(a.begin(),a.end());
    for(int i = 0; i < n; i++) {
        ans -= (long long) (n - i) * a[i];
    }
    cout << ans << endl;
    return 0;
}




