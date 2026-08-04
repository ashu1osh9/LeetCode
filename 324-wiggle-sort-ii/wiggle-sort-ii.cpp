class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        int n = temp.size();

        vector<int> ans(n);

        int left = (n - 1) / 2;
        int right = n - 1;

        for (int i = 0; i < n; i++) {

            if (i % 2 == 0) {
                ans[i] = temp[left];
                left--;
            }
            else {
                ans[i] = temp[right];
                right--;
            }
        }

        nums = ans;
    }
};