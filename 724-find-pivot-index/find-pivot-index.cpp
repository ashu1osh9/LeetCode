class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        vector<int> res;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res.push_back(sum);
        }

        int total = res[res.size() - 1];

        for(int i = 0; i < res.size(); i++) {

            int leftSum = 0;

            if(i > 0)
                leftSum = res[i - 1];

            int rightSum = total - res[i];

            if(leftSum == rightSum)
                return i;
        }

        return -1;
    }
};