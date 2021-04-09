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


    int n,x;
    cin >> n >> x;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());


    int idx1 = 0, idx2 = n-1;
    int skipped = 0; // singles :(
    int cnt = 0;

    while(idx1 <= idx2) {
        ++cnt;
        while(idx2 > idx1 && v[idx1] + v[idx2] > x) {
            --idx2;
            ++skipped;
        }
        ++idx1;
        --idx2;
    }
    
    cout << cnt + skipped << endl;



    return 0;
}


