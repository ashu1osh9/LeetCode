class Solution {
public:

    int solve(long long x, long long ans) {

        if(x == 0)
            return ans;

        int digit = x % 10;

        ans = ans * 10 + digit;

        if(ans < INT_MIN || ans > INT_MAX)
            return 0;

        return solve(x / 10, ans);
    }

    int reverse(int x) {

        return solve(x, 0);
    }
};