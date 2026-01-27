class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> cnt{{0, 1}};
        int sum = 0, res = 0;
        
        for (int x : nums) {
            sum += x & 1;
            res += cnt[sum - k];
            cnt[sum]++;
        }
        
        return res;
    }
};
 