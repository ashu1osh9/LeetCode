class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int,int>, int> mp;

        int same = 0;
        int mx = 0;

        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                same++;
            }
            else {
                int a = min(nums[i], nums[i + 1]);
                int b = max(nums[i], nums[i + 1]);

                mp[{a, b}]++;
                mx = max(mx, mp[{a, b}]);
            }
        }

        return same + mx;
    }
};