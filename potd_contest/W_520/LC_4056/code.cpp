#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<int> ends;
        for (auto& interval : intervals) {
            ends.push_back(interval[1]);
        }
        sort(ends.begin(), ends.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int nonIntersecting = lower_bound(ends.begin(), ends.end(), start)- ends.begin();
            ans += i - min(i, nonIntersecting);
        }
        return ans;
    }
};