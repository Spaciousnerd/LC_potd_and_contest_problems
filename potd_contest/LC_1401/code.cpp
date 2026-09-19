#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkOverlap(int radius, int xc, int yc, int x1, int y1, int x2, int y2) {
        int x,y;
        if(x1>xc) x = x1;
        else if(x2<xc) x = x2;
        else x = xc;
        if(y1>yc) y = y1;
        else if(y2<yc) y = y2;
        else y = yc;

        int s = (xc-x)*(xc-x) + (yc-y)*(yc-y) - radius*radius;
        return s<=0;
    }
};