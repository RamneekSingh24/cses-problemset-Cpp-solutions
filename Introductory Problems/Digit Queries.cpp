#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>



using namespace std;

// Solution using binary search 

long long num_digits[19];
long long max_num[19];
long long p10[19];
const int MAX_DIGITS = 17;


void init() {
    num_digits[0] = 0;
    max_num[0] = 0;
    p10[0] = 1;
    int num = 1;

    long long pow10 = 1;

    for(; num <= MAX_DIGITS; num++) {
        num_digits[num] = num_digits[num - 1] + 9 * num * pow10;
        max_num[num] = max_num[num - 1] + 9 * pow10;
        pow10 *= 10;
        p10[num] = pow10;
    }

}

int get_num_digits(long long x) {
    int c = 0;
    while(x) {
        ++c;
        x /= 10;
    }
    return c;
}

long long get_start_pos(long long x) {
    if(x == 0) return 0;
    int num = get_num_digits(x);
    long long ans = num_digits[num-1] + (x -1 - max_num[num-1]) * num + 1;
    return ans;
}


int main() {

#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    init();

    int q;
    cin >> q;
    while(q--) {

        long long pos;
        cin >> pos;

        long long lx = 1, rx = p10[MAX_DIGITS];
        int itr = 0;

        while(lx < rx && itr < 100) {
            ++itr;
            long long mx = (lx + rx) / 2;
    
            long long pos_mx = get_start_pos(mx), dig_mx = get_num_digits(mx);
            if(pos < pos_mx + dig_mx) {
                rx = mx;
            }
            else{
                lx = mx + 1;
            }
        }



        int ans = (lx / p10[get_start_pos(lx) + get_num_digits(lx) - 1 - pos]) % 10;
        cout << ans << endl;



    }


    return 0;
}


