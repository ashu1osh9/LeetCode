
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {

//         int j = 0;

//         for (int i = 0; i < nums.size(); i++) {

//             if (nums[i] != 0) {
//                 swap(nums[i], nums[j]);
//                 j++;
//             }

//         }
//     }
// };

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        vector<int> temp;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                temp.push_back(nums[i]);
        }

        while (temp.size() < nums.size()) {
            temp.push_back(0);
        }

        nums = temp;
    }
};