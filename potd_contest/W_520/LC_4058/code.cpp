#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        long long base = 0;
        for(int i=0;i<n;i++){
            if(i%2==0) base+=nums[i];
            else base-=nums[i];
        }
        long long bestGain = 0;
        long long pref = 0;
        long long maxPref[2] = {0,LLONG_MIN};
        for(int i=1;i<=n;i++){
            if(i%2==1) pref+=nums[i-1];
            else pref-=nums[i-1];
            int parity = i%2;
            if(maxPref[parity]!=LLONG_MIN)
                bestGain=max(bestGain,-2LL*(pref-maxPref[parity]));

            maxPref[parity]=max(maxPref[parity],pref);
        }
        return base+bestGain;
    }
};