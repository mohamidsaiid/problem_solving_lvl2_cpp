// https://leetcode.com/problems/koko-eating-bananas/description/
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(),piles.end());
        int size = piles.size();
        vector<int> mins;
        int m = r;
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            long int x = 0;
            for(int i = 0; i < size; i++)
            {
                x += ceil((double) piles[i]/ mid);
            }
            if(x <= h)
            {
                m = min(m, mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return m;
    }
};
