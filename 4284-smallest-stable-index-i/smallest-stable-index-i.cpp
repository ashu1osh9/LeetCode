class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int> maxhp;
        priority_queue<int, vector<int>, greater<int>> minhp;

        for(int i = 0; i < n; i++){
            minhp.push(nums[i]);
        }

        for(int i = 0; i < n; i++){
            maxhp.push(nums[i]);

            int maxi = maxhp.top();
            int mini = minhp.top();

            int diff = maxi - mini;

            if(diff <= k){
                return i;
            }

            vector<int> temp;

            while(!minhp.empty() && minhp.top() < nums[i]){
                temp.push_back(minhp.top());
                minhp.pop();
            }

            if(!minhp.empty() && minhp.top() == nums[i]){
                minhp.pop();
            }

            for(int x : temp){
                minhp.push(x);
            }
        }

        return -1;
    }
};