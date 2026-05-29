class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int,
                       vector<int>,
                       greater<int>> hmin;

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            hmin.push(nums[i]);

            if(hmin.size() > k) {
                hmin.pop();
            }
        }

        return hmin.top();
    }
};