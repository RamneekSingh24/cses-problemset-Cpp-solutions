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

const int MOD = 1e9 + 7;
const int INF = 1e9;

const int MX = 100 * 1000 + 10;
bool can_make[MX] = {0};

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

    can_make[0] = 1;

    for(int i = 0; i < n; i++) {
        for(int c = MX; c >= v[i]; c--) {
            can_make[c] |= can_make[c - v[i]];
        }
    }

    vector<int> ans;
    for(int i = 1 ; i < MX; i++) {
        if(can_make[i]) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] <<  " ";
    }
    cout << endl;
    return 0;
}





