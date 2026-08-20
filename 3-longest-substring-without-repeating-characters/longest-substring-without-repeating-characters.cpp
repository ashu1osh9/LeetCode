class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;

        int l = 0;
        int r ;
        int ans = 0;

        for(r = 0;r<s.size();r++){


            char c = s[r];

            while(mp.find(c)!= mp.end()){

                mp.erase(s[l]);
                l++;





            }


            mp[s[r]]++;

            ans = max(ans, r-l + 1);

        }
        return ans ;
        
    }
};