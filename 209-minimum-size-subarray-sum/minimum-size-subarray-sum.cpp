
class Solution {
public:
    int minSubArrayLen(int t, vector<int>& a) {
        int l = 0, s = 0;
        int ans = INT_MAX;

        for (int r = 0; r < a.size(); r++) {
            s += a[r];          // add element

            while (s >= t) {   // valid window
                ans = min(ans, r - l + 1);
                s -= a[l];     // remove left element
                l++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
