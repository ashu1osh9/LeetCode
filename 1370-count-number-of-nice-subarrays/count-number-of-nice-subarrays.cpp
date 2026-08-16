class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        mp[0] = 1;

        int prefix = 0;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] % 2 != 0)
                prefix++;

            int need = prefix - k;

            if(mp.find(need) != mp.end())
                ans += mp[need];

            mp[prefix]++;
        }

        return ans;
    }
};