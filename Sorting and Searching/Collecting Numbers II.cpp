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

    int n, m;
    cin >> n >> m;
    vector<int> pos(n+2);
    vector<int> nums(n+2);

    for(int i = 1; i <=n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
        nums[i] = x;
    }
    pos[0] = 0;
    pos[n+1] = n+1;
    nums[0] = 0;
    nums[n+1] = n+1;

    for(int i = 1; i <= n; i++) {
        if(pos[i] < pos[i-1]) {
            ++rounds;
        }
    }

    int contri;
    while(m--){
        int p1, p2;
        cin >> p1 >> p2;
        int n1 = nums[p1], n2 = nums[p2];

        contri = (pos[n1] < pos[n1-1]) + (pos[n1] > pos[n1+1]);
        contri += (pos[n2] < pos[n2-1]) + (pos[n2] > pos[n2+1]);
        if(abs(n2-n1) == 1) {
            contri -= pos[max(n1, n2)] < pos[min(n1, n2)];
        }

        rounds -= contri;
        swap(nums[p1], nums[p2]);
        swap(n1, n2);
        pos[n1] = p1, pos[n2] = p2;

        contri = (pos[n1] < pos[n1-1]) + (pos[n1] > pos[n1+1]);
        contri += (pos[n2] < pos[n2-1]) + (pos[n2] > pos[n2+1]);
        if(abs(n2-n1) == 1) {
            contri -= pos[max(n1, n2)] < pos[min(n1, n2)];
        }

        rounds += contri;
        cout << rounds << endl;

    }

    return 0;
}




