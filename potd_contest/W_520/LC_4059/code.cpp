#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        vector<vector<int>>segments;
        segments.push_back(nums);
        vector<int>power;
        for(int bit = 14;bit>=0;bit--){
            int prefix = 0;
            bool stopped = false;
            vector<vector<int>>nextSegments;
            for (auto &seg : segments) {
                if (stopped){
                    nextSegments.push_back(seg);
                    continue;
                }
                vector<int> ones, zeros;
                for (int x : seg) {
                    if ((x >> bit) & 1) ones.push_back(x);
                    else zeros.push_back(x);
                }
                if (zeros.empty()) {
                    prefix += seg.size();
                    nextSegments.push_back(seg);
                } else {
                    power.push_back(prefix + ones.size());
                    if(!ones.empty()) nextSegments.push_back(ones);
                    if(!zeros.empty()) nextSegments.push_back(zeros);
                    stopped = true;
                }
            }
            if(!stopped) power.push_back(prefix);
            segments = nextSegments;
        }
        return power;
    }
};