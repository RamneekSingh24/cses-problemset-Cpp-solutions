#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>
 
using namespace std;
 
vector<string> strs;
vector<int> chars;
vector<int> char_count(26,0);
string curr;
 
void generate(int indx, int cant_take, int len) {
 
    if(indx == len) {
        strs.push_back(curr);
        return;
    }
 
    for(int c : chars) {
        if(c == cant_take || char_count[c] == 0) {
            continue;
        }
        else{
            for(int num = 1; num <= char_count[c]; num++) {
                for(int itr = 0; itr < num; itr++) {
                    curr[indx++] = 'a' + c;
                }
                char_count[c] -= num;
                generate(indx, c, len);
                char_count[c] += num;
                indx -= num;
            }
        }
    }
}
 
 
 
int main() {
 
    #ifdef MYPC
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
 
 
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        char_count[s[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(char_count[i]) {
            chars.push_back(i);
        }
    }
    curr = string(s.length(), '$');
    generate(0, -1, (int)s.length());
    sort(strs.begin(), strs.end());
    cout << strs.size() << endl;
    for(string str : strs) {
        cout << str << endl;
    }
 
    return 0;
}
