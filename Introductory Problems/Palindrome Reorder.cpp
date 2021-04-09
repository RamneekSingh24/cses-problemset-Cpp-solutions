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
 
    string s;
    cin >> s;
    int n = s.length();
    int char_count[26];
    memset(char_count, 0, sizeof(char_count));
    for(int i = 0; i < n; i++) {
        char_count[s[i] - 'A']++;
    }
    int odd_char = 0 , odd_char_count = 0;
    for(int i = 0; i < 26; i++) {
        if(char_count[i] & 1) {
            ++odd_char_count;
            odd_char = i;
        }
    }
 
    if( n % 2 != odd_char_count % 2  || odd_char_count > 1) {
        cout << "NO SOLUTION" << endl;
    }
    else {
        string ans = string(n, 'A' + odd_char);
        int pos = 0;
        for(int i = 0; i < 26; i++) {
            if(char_count[i] & 1) {
                continue;
            }
            else {
                for(int j = 0 ; j < char_count[i] / 2; j++) {
                    ans[pos] = 'A' + i;
                    ans[n-1-pos++] = 'A' + i;
                }
            }
        }
        cout << ans << endl;
    }
 
    return 0;
}
