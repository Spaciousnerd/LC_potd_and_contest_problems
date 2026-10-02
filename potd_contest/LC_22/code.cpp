#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string s = "";
        solve(s,0,0,n,res);
        return res;
    }
    void solve(string& s,int open,int close,int& n,vector<string>&res){
        if(close>open || open>n) return;
        if(s!="" && open==close && open+close == 2*n){
            res.push_back(s);
            return;
        }
        if(open<n){
            s.push_back('(');
            solve(s,open+1,close,n,res);
            s.pop_back();
        }
        if(close<n){
            s.push_back(')');
            solve(s,open,close+1,n,res);
            s.pop_back();
        }
        return;
    }
};