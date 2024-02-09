// https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> x;
        for(int i = 0; i < size-2;i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = size - 1;
            while (l < r)
            {
                int temp = nums[i] + nums[l] + nums[r];
                if(temp > 0) r--;
                else if(temp < 0) l++;
                else
                {
                    vector<int> temp{nums[i], nums[l], nums[r]};
                    sort(temp.begin(), temp.end());
                    x.push_back(temp);
                    while(l < r && nums[l] == nums[l+1])
                    {
                        l++;
                    }
                    l++;
                    while(l < r && nums[r] == nums[r-1])
                    {
                        r--;
                    }
                    r--;
                }
            }
        }
        return x;
    }
};
