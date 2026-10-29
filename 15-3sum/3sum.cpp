// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>> st;
//         int n = nums.size();

//         for(int i = 0; i < n; i++) {
//             for(int j = i + 1; j < n; j++) {
//                 for(int k = j + 1; k < n; k++) {
//                     if(nums[i] + nums[j] + nums[k] == 0) {
//                         vector<int> v = {nums[i], nums[j], nums[k]};
//                         sort(v.begin(), v.end());
//                         st.insert(v);
//                     }
//                 }
//             }
//         }

//         return vector<vector<int>>(st.begin(), st.end());
//     }
// };


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0; i < n - 2; i++) {

            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int l = i + 1, r = n - 1;

            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if(sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});

                    l++;
                    r--;

                    while(l < r && nums[l] == nums[l-1])
                        l++;

                    while(l < r && nums[r] == nums[r+1])
                        r--;
                }
                else if(sum < 0) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }

        return ans;
    }
};