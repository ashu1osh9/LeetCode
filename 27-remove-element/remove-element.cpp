class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++){
            if(nums[i] != val){
                mp[nums[i]]++;
            }
        }

        nums.clear();

        for(auto x : mp){
            for(int i = 0; i < x.second; i++){
                nums.push_back(x.first);
            }
        }

        return nums.size();
    }
};