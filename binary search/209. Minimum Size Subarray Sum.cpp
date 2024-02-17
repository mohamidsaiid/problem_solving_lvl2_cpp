// https://leetcode.com/problems/minimum-size-subarray-sum/description/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        bool c = 0;
        int start = 0, end = 0, size = nums.size(), sum = 0;
        int minn = size;
        while(end < size)
        {
            sum = sum + nums[end];
            end++;
            while(sum >= target)
            {
                minn = min(end - start , minn);
                sum = sum - nums[start++];
                c = 1;
            }
        }
        return c ? minn : 0;
    }
};
