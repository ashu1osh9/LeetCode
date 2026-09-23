class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();

        int total = 0;

        for(int i = 0; i < n; i++) {
            total += nums[i];
        }

        int target = total - x;

        int l = 0;
        int sum = 0;
        int maxi = -1;

        for(int r = 0; r < n; r++) {

            sum += nums[r];

            while(l <= r && sum > target) {
                sum -= nums[l];
                l++;
            }

            if(sum == target) {
                maxi = max(maxi, r - l + 1);
            }
        }

        if(maxi == -1)
            return -1;

        return n - maxi;
    }
};