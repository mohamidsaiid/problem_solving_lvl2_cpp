// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int size = nums.size();
        vector<int> cpy (nums.begin(), nums.end());
        sort(cpy.begin(), cpy.end());
        int s = size + 1, e = size + 1;
        int l = 0, r = size - 1;
        while(l < size && r >= 0)
        {
            if(cpy[l] != nums[l] && s > size) s = l;
            if(cpy[r] != nums[r] && e > size) e = r;
            --r;
            ++l;
            if(s < size && e < size) break;
        }
        if(e == s) return 0;
        return e - s + 1;
    }
};
