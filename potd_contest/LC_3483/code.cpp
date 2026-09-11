#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // brute forced : optimal on LC 2094 and below
        int n = digits.size();
        unordered_set<int>s;
        int total = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                for(int k=0;k<n;k++){
                    if(j==k || i==k || digits[k]%2) continue;
                    int num =digits[i]*100 + digits[j]*10+digits[k];
                    if(num>=100 && s.find(num)==s.end()){
                        total++;
                        s.insert(num);
                    }

                }
            }
        }
        return total;
    }
};