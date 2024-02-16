// https://leetcode.com/problems/permutations/description/
class Solution {
public:
    vector<int> perm;
    vector<vector<int>> tot;
    void fun(vector<int> nums, int size, vector<bool> &chck)
    {
        if(perm.size() == size) tot.push_back(perm);
        else
        {
            for(int i = 0; i < size; i++)
            {
                if(chck[i]) continue;
                chck[i] = true;
                perm.push_back(nums[i]);
                fun(nums, size, chck);
                chck[i] = false;
                perm.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        vector<bool> chck(size, 0);
        fun(nums, size, chck);
        return tot;
    }
};
