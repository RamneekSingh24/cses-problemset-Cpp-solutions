#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory.h>
 
using namespace std;
const int SZ = 1 << 16;
int from[SZ];
int to[SZ];
int move_no = 0;
 
void move(int f, int t, int e, int num) {
    if(num == 1) {
        from[move_no] = f;
        to[move_no++] = t;
        return;
    }
    move(f, e, t, num - 1);
    from[move_no] = f;
    to[move_no++] = t;
    move(e, t, f, num-1);
}
 
int main() {
 
    #ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
 
    int n;
    cin >> n;
    move(1, 3, 2, n);
    cout << move_no << endl;
    for(int i = 0 ; i < move_no; i++) {
        cout << from[i] << " " << to[i] << endl;
    }
 
    return 0;
}
