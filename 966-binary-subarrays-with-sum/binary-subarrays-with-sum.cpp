class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        unordered_map<int,int>mp;


        int sum = 0;
        mp[0] = 1;

        int count = 0;
        for(int i = 0;i<nums.size();i++){

            sum+= nums[i];


            int rem = sum-goal;

            if(mp.find(rem)!=mp.end()){

                auto res = mp[rem];

                count +=res;

            }

            mp[sum] ++; 



        }

        return count;
        
    }
};