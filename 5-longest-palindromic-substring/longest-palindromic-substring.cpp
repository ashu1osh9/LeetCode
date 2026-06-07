class Solution {
public:

    string ans = "";

    void check(string &s, int l, int r) {

        while (l >= 0 && r < s.size() && s[l] == s[r]) {

            if ((r - l + 1) > ans.size()) {
                ans = s.substr(l, r - l + 1);
            }

            l--;
            r++;
        }
    }

    string longestPalindrome(string s) {

        for (int i = 0; i < s.size(); i++) {

            check(s, i, i);       // odd
            check(s, i, i + 1);   // even
        }

        return ans;
    }
};