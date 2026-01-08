class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++) {

            // case 1: last element
            if(i == n - 1) {
                if(nums[i] > nums[0]) {
                    count++;
                }
            }
            // case 2: normal elements
            else {
                if(nums[i] > nums[i + 1]) {
                    count++;
                }
            }

        }

        if(count <= 1)
            return true;
        else
            return false;
    }
};
