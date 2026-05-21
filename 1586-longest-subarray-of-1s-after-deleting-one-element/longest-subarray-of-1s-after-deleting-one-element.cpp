// class Solution {
// public:

//     int n;

//     int findMax(vector<int>& nums, int skip_idx) {

//         int current = 0;
//         int maxLen = 0;

//         for(int i = 0; i < n; i++) {

//             if(i == skip_idx) {
//                 continue;
//             }

//             if(nums[i] == 1) {
//                 current++;
//                 maxLen = max(maxLen, current);
//             }
//             else {
//                 current = 0;
//             }
//         }

//         return maxLen;
//     }

//     int longestSubarray(vector<int>& nums) {

//         n = nums.size();

//         int result = 0;
//         bool hasZero = false;

//         for(int i = 0; i < n; i++) {

//             if(nums[i] == 0) {

//                 hasZero = true;
//                 result = max(result, findMax(nums, i));
//             }
//         }

//         // all elements are 1
//         if(!hasZero)
//             return n - 1;

//         return result;
//     }
// };
class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n = nums.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        // consecutive 1s from left
        for(int i = 0; i < n; i++) {

            if(nums[i] == 1) {

                left[i] = 1;

                if(i > 0)
                    left[i] += left[i - 1];
            }
        }

        // consecutive 1s from right
        for(int i = n - 1; i >= 0; i--) {

            if(nums[i] == 1) {

                right[i] = 1;

                if(i < n - 1)
                    right[i] += right[i + 1];
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {

            // delete current element

            int leftOnes = (i > 0) ? left[i - 1] : 0;
            int rightOnes = (i < n - 1) ? right[i + 1] : 0;

            ans = max(ans, leftOnes + rightOnes);
        }

        return ans;
    }
};