class Solution {
public:
    int findPeakElement(vector<int>& nums) {
            if(nums.size()==1){
               return 0;

            }
        for(int i = 1;i<nums.size()-1;i++){

            int e = nums[i];
            int re = nums[i+1];
            int le = nums[i-1];

            if(e >re && e >le) return i;


        }
        if(nums[0] > nums[1])
            return 0;

        return nums.size() - 1;
    }
};