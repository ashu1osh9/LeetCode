class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>st;
        vector<int>ans;

        for(int i = 0;i<nums.size();i++){
            st.insert(nums[i]);
            if(st.size()>k){
                st.erase(st.find(nums[i-k]));
            }
            if(st.size() == k){
                ans.push_back(*st.rbegin());
            }


        }
        return ans;
        
    }
};