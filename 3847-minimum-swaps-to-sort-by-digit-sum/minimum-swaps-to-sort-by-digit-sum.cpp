class Solution {
public:
    vector<pair<int,int>>ans;
    int minSwaps(vector<int>& nums) {

        for(int i = 0;i<nums.size();i++){

            int value = nums[i];

            int sum = 0;
            while(value>0){
                sum+= value%10;
                value = value/10;
            }

            ans.push_back({sum , nums[i]});


        }
        sort(ans.begin(), ans.end());
        unordered_map<int,int>map;
        int n = nums.size();
        int count = 0;
        for(int i = 0;i<n;i++){
            map[ans[i].second] = i;

        }

        for(int i = 0;i<n;i++){
            while(ans[i].second!= nums[i]){
                int j = map[nums[i]];
                swap(nums[i], nums[j]);
                count++;
            }
        }
        return count;
        
    }
};