class Solution {
public:
    int maxi = INT_MIN;
    int minMoves(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){


        maxi = max(maxi,nums[i]);


        }

        int count = 0;

        for(int i = 0;i<nums.size();i++){
            count+=maxi- nums[i];
        }
        return count;
    }
};