#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main() {
 
    #ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
 
    int t; cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int x1 = 2 * a - b, x2 = 2 * b - a;
        if(x1 >= 0 && x2 >=0 && x1 % 3 == 0 && x2 % 3 == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
