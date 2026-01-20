class Solution {
public:
    int lengthOfLongestSubstring(string s) {
   int n = s.size();
        int h[256];

        for(int i = 0; i < 256; i++) {
            h[i] = -1;
        }

        int l = 0, mx = 0;

        for(int r = 0; r < n; r++) {

            if(h[s[r]] != -1) {
                l = max(l, h[s[r]] + 1);
            }

            mx = max(mx, r - l + 1);
            h[s[r]] = r;
        }

        return mx;
    }
};