class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int maxi = INT_MIN;
        int count = 0;

        for(auto x : nums){
            if(x == 0){

                count = 0;

            }
            else{
                count++;

                maxi = max(maxi,count);
            }
        }
        if(maxi <0) return 0;
        return maxi;
        
    }
};