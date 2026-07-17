class Solution {
public:

    void generate(int idx, int end, int cnt, int sum,
                  vector<int>& nums,
                  vector<vector<int>>& subsetSum) {

        if (idx == end) {
            subsetSum[cnt].push_back(sum);
            return;
        }

        // Take
        generate(idx + 1, end, cnt + 1, sum + nums[idx],
                 nums, subsetSum);

        // Not Take
        generate(idx + 1, end, cnt, sum,
                 nums, subsetSum);
    }

    int minimumDifference(vector<int>& nums) {

        int n = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        vector<vector<int>> leftSum(n + 1);
        vector<vector<int>> rightSum(n + 1);

        generate(0, n, 0, 0, left, leftSum);
        generate(0, n, 0, 0, right, rightSum);

        for (int i = 0; i <= n; i++)
            sort(rightSum[i].begin(), rightSum[i].end());

        int total = accumulate(nums.begin(), nums.end(), 0);

        int ans = INT_MAX;

        for (int leftCnt = 0; leftCnt <= n; leftCnt++) {

            int rightCnt = n - leftCnt;

            for (int leftSubsetSum : leftSum[leftCnt]) {

                // Target = total/2
                int target = total / 2 - leftSubsetSum;

                auto it = lower_bound(rightSum[rightCnt].begin(),
                                      rightSum[rightCnt].end(),
                                      target);

                if (it != rightSum[rightCnt].end()) {

                    int sum1 = leftSubsetSum + *it;
                    int sum2 = total - sum1;

                    ans = min(ans, abs(sum1 - sum2));
                }

                if (it != rightSum[rightCnt].begin()) {

                    --it;

                    int sum1 = leftSubsetSum + *it;
                    int sum2 = total - sum1;

                    ans = min(ans, abs(sum1 - sum2));
                }
            }
        }

        return ans;
    }
};