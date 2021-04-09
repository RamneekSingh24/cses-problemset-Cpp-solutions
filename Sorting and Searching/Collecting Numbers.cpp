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
 
    int rounds = 1;
 
    int n; cin >> n;
    vector<int> pos(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        pos[x] = i;
    }
 
    for(int i = 1; i < n; i++) {
        if(pos[i] < pos[i-1]) {
            ++rounds;
        }
    }
    cout << rounds << endl;
    return 0;
}

