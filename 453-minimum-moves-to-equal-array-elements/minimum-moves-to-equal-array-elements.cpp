class Solution {
public:
    int minMoves(vector<int>& nums) {
     sort(nums.begin(),nums.end());

        int small = nums[0];
        int count = 0;
        for(auto x : nums ){

            count += x-small;

        }
        return count ;
        
    }
};