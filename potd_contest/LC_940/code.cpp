#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int distinctSubseqII(string s) {
    int n = s.size();
    vector<int>lastSeen(26,-1);
    vector<int>subs(n+1,0);
    subs[0] = 1;
    for(int i=1;i<=n;i++){
        int dup = lastSeen[s[i-1]-'a']==-1 ? 0 :  subs[lastSeen[s[i-1]-'a']-1];
        subs[i] = (((subs[i-1]<<1)%mod - dup)%mod + mod)%mod;
        lastSeen[s[i-1]-'a'] = i;
    }
    return (subs[n] - 1 + mod) % mod;;
}