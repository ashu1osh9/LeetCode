class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for(int i = 0; i < nums.size(); i++) {

            vector<long long> newDp(k, 0);

            int rem = nums[i] % k;

            // nums[i] se naya subarray
            newDp[rem]++;

            // purane subarrays ko nums[i] ke saath extend karo
            for(int j = 0; j < k; j++) {

                int newRem = (j * rem) % k;

                newDp[newRem] += dp[j];
            }

            // current position par end hone wale
            // saare subarrays ko answer mein add karo
            for(int j = 0; j < k; j++) {
                ans[j] += newDp[j];
            }

            dp = newDp;
        }

        return ans;
    }
};