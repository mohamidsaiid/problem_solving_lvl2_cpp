// https://leetcode.com/problems/sqrtx/description/
class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        int l = 0, r = x;
        int mid;
        while(l <= r)
        {
            mid = l + (r - l) / 2;
            if((long)mid * mid == x) return mid;
            else if((long)mid * mid > x) r = mid - 1;
            else l = mid + 1;
        }
        return r;
    }
};
