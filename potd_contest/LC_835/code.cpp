#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for(int row_offset=-n+1;row_offset<n;row_offset++){
            for(int col_offset=-n+1;col_offset<n;col_offset++){
                ans = max(ans,countOverlap(img1,img2,row_offset,col_offset));
            }
        }
        return ans;
    }
    int countOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2,int row_offset,int col_offset){
        int n = img1.size();
        int count= 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int i2 = i+row_offset;
                int j2 = j+col_offset;
                if(i2>=0 && i2<n && j2>=0 && j2<n){
                    if(img1[i][j]==1 && img1[i][j] == img2[i2][j2]){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};