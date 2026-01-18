class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;// slow poniter -- unique elements ko point karega 
        int j = 1; // fast pointer 
        int n = nums.size();
        if(n==0)
        return 0;
        for(;j<n;j++){
            if(nums[i]!=nums[j]){ // barabar nhi hai 
                i++; //  unique elements likhen hai 
                nums[i] = nums[j];
            }
        }
        return i+1;


        
    }
};