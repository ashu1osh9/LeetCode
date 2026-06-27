class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int i = 0;i<nums.size();i++){
            map[nums[i]]++;
        }
        int result = 0;
        for(auto num:map){
            if(num.second<=1){
                result = num.first;
                break;
            }
        }
        return result;
    }
        
    
};