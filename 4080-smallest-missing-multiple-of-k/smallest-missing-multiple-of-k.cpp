class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int , int> mp ;
        for(auto ele : nums){
            mp[ele]++ ;
        }
        int i = k ;
        while(true){
          if(mp.find(i)==mp.end()) return i ;
          i+=k ;
        }
    }
};