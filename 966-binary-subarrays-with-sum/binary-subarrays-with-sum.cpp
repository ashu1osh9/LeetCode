class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;

        int current = 0;
        int previous = 0;
        int ans = 0;
    mp[0] = 1;


        for(int x : nums){


            current +=x;

            previous = current - goal;


            if(mp.count(previous)){

                ans += mp[previous];


            }

            mp[current]++;






        }
        return ans;
    }
};