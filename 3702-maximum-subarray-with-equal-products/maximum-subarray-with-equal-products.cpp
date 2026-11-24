class Solution {
public:
    int maxLength(vector<int>& nums) {
        int l = 0;
        int maxi = 2;

        vector<int> primes = {2, 3, 5, 7};
        unordered_map<int, int> mp;

        for(int r = 0; r < nums.size(); r++) {

            // Add prime factors
            for(int p : primes) {
                if(nums[r] % p == 0) {
                    mp[p]++;
                }
            }

            // Shrink invalid window
            while(mp[2] > 1 || mp[3] > 1 ||
                  mp[5] > 1 || mp[7] > 1) {

                for(int p : primes) {
                    if(nums[l] % p == 0) {
                        mp[p]--;
                    }
                }

                l++;
            }

            maxi = max(maxi, r - l + 1);
        }

        return maxi;
    }
};