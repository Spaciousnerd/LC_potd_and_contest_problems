#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>>events;
        for(auto &it : intervals){
            events.push_back({it[0],0});
            events.push_back({it[1],1});
        }
        sort(events.begin(),events.end());
        long long ans = 0;
        int active = 0;
        for(auto & [pos,type] : events){
            if(type==0){
                ans+=active;
                active++;
            }else active--;
        }
        return ans;
    }
};