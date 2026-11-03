class Solution {
public:
    void solve(int index, vector<int>& ans, int n,
               vector<int>& nums2, int value) {

        for(int i = index + 1; i < n; i++) {
            if(nums2[i] > value) {
                ans.push_back(nums2[i]);
                return;
            }
        }

        ans.push_back(-1);
    }

    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {

        int n = nums2.size();
        unordered_map<int,int> mp;
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            mp[nums2[i]] = i;
        }

        for(int j = 0; j < nums1.size(); j++) {
            int value = nums1[j];

            if(mp.find(value) == mp.end()) {
                ans.push_back(-1);
            }
            else {
                int index = mp[value];
                solve(index, ans, n, nums2, value);
            }
        }

        return ans;
    }
};