#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverseDegree(string s) {
        int deg = 0;
        for(int i=0;i<s.size();i++){
            deg+= (i+1)*('z'-s[i]+1);
        }
        return deg;
    }
};