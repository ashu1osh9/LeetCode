class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();

        // Prefix Maximum
        vector<int> pm(n);

        pm[0] = nums[0];

        for(int i = 1; i < n; i++) {
            pm[i] = max(pm[i - 1], nums[i]);
        }

        // Suffix Minimum
        vector<int> sm(n);

        sm[n - 1] = nums[n - 1];

        for(int j = n - 2; j >= 0; j--) {
            sm[j] = min(nums[j], sm[j + 1]);
        }

        // Find first stable index
        for(int i = 0; i < n; i++) {

            int diff = pm[i] - sm[i];

            if(diff <= k) {
                return i;
            }
        }

        return -1;
    }
};