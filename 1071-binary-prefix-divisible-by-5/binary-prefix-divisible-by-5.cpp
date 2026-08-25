class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int current = 0;
        vector<bool> ans;

        for(int i = 0; i < nums.size(); i++) {

            current <<= 1;
            current |= nums[i];

            current %= 5;

            if(current == 0)
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};