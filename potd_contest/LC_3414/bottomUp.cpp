#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    struct Node{
        long long score = -1;
        vector<int>idxs;
    };
    vector<int>nextIdx;
    vector<vector<Node>>dp;
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();
        // store starting index of each interval
        for(int i=0;i<n;i++) intervals[i].push_back(i);
        // sort intervals for start point
        sort(intervals.begin(),intervals.end());
        nextIdx.resize(n);

        for(int i=0;i<n;i++){
            int end = intervals[i][1];
            nextIdx[i] = findNext(intervals,end); //binary search
        }
        int k = 4;
        dp.assign(n+1,vector<Node>(k+1));
        // return solve(intervals,0,k).idxs;
        for(int i=n-1;i>=0;i--){
            int wt = intervals[i][2];
            int idx = intervals[i][3];
            int j = nextIdx[i];
            for(int k=1;k<=4;k++){
                Node skip = dp[i+1][k]; // solve(intervals,i+1,k)
                Node temp = dp[j][k-1]; // solve(intervals,j,k-1)
                Node take;
                take.score = temp.score + wt; 
                take.idxs = temp.idxs;
                take.idxs.push_back(idx);
                sort(begin(take.idxs),end(take.idxs));
                Node result;
                if(skip.score > take.score) result = skip;
                else if(skip.score < take.score) result = take;
                else {
                    result = (skip.idxs < take.idxs) ? skip : take;
                }
                dp[i][k] = result;
            }
        }
        return dp[0][k].idxs;
    }
    int findNext(vector<vector<int>>& intervals,int r){
        int low = 0,high=n-1;
        int res = n;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(intervals[mid][0] > r){
                res = mid;
                high = mid - 1;
            }else low  = mid+1;
        }
        return res;
    }
};