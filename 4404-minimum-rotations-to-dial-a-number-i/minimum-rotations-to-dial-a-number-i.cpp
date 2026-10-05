class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        int curr = 0;

        for(char c : s) {
            int x = c - '0';

            int d = abs(curr - x);

            ans += min(d, 10 - d);

            curr = x;
        }

        return ans;
    }
};