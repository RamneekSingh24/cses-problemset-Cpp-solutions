#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main() {
 
    #ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
 
    int n; cin >> n;
    int num = 1 << n;
    bool used[num];
    memset(used, false, sizeof(used));
 
    int curr_num = 1;
 
    while(num--) {
        for(int bit = 0; bit < n; bit++) {
            if(!used[curr_num ^ (1 << bit)]) {
                curr_num ^= 1 << bit;
                break;
            }
        }
        for(int bit = n-1; bit >= 0; bit--) {
            if(curr_num & (1 << bit)) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
        cout << endl;
        used[curr_num] = true;
    }
 
    
