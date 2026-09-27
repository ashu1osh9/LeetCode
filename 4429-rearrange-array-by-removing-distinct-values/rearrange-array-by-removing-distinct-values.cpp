class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        map<int, int> mp;

        // Hashing / frequency
        for (int x : nums) {
            mp[x]++;
        }

        vector<int> ans;

        while (ans.size() < nums.size()) {

            for (auto &it : mp) {

                if (it.second > 0) {
                    ans.push_back(it.first);
                    it.second--;
                }
            }
        }

        return ans;
    }
};