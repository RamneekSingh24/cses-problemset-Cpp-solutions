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
 
struct node {
    int num;
    node* next;
    node* prev;
};
 
int main() {
 
#ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
 
    fast_io;
 
    int n;
    cin >> n;
    vector<node> nodes(n);
    for(int i = 0; i < n; i++) {
        nodes[i].num = i + 1;
        nodes[i].prev = &nodes[(i - 1 + n) % n];
        nodes[i].next = &nodes[(i + 1) % n];
    }
    node atnode = nodes[0];
 
    while(n--) {
        atnode = *atnode.next;
        cout << atnode.num << " ";
        atnode.prev->next = atnode.next;
        atnode.next->prev = atnode.prev;
        atnode = *atnode.next;
    }
    cout << endl;
 
 
    return 0;
}
 
 
 
 
