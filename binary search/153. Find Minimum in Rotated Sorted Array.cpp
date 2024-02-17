// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
class Solution {
public:
    int findMin(vector<int>& x) {
        int l = 0, r = x.size() - 1;
        int ans = x[0];
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(x[mid] >= x[l] && x[mid] >= x[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;    
            }
            ans = min(x[mid], ans);
        }
        return ans;
    }
};
