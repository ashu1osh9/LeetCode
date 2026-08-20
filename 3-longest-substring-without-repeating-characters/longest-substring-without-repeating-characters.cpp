class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>st;

        int l = 0;
        int r ;
        int ans = 0;

        for(r = 0;r<s.size();r++){

            char c = s[r];

        
            while(st.find(c)!=st.end()){

                st.erase(s[l]);


                l++;




            }

            st.insert(c);

            ans = max(ans,r-l +1);




        




        }
        return ans;
        
    }
};