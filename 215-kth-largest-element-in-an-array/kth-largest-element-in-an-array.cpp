class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> hpmin; // finding the largest elements
        for(int i = 0;i<nums.size();i++){
            hpmin.push(nums[i]);
            if(hpmin.size()>k){
                hpmin.pop();
            }
        }
        return hpmin.top();

        
    }
};