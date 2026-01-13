class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int l = 0;
        int cnt = 0;

        for(int r = 2; r < n; r++) {
            if(s[l] != s[l+1] &&
               s[l] != s[r]   &&
               s[l+1] != s[r]) {
                cnt++;
            }
            l++;
        }

        return cnt;
    }
};
