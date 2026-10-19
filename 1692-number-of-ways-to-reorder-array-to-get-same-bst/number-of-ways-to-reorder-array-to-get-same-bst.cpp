
class Solution {
public:
    long long mod = 1e9 + 7;
    vector<vector<long long>> c;

    long long result(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return 1;

        vector<int> left, right;

        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        int l = left.size();
        int r = right.size();

        long long way = c[n-1][l];
        long long a = result(left);
        long long b = result(right);

        return way * a % mod * b % mod;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        c.assign(n+1, vector<long long>(n+1, 0));

        for(int i = 0; i <= n; i++) {
            c[i][0] = c[i][i] = 1;

            for(int j = 1; j < i; j++) {
                c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
            }
        }

        return (result(nums) - 1 + mod) % mod;
    }
};
