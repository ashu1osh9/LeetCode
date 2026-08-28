class Solution {
public:

    long long sumOfMax(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Greater Element
        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (st.empty())
                left[i] = i + 1;
            else
                left[i] = i - st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Greater or Equal Element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if (st.empty())
                right[i] = n - i;
            else
                right[i] = st.top() - i;

            st.push(i);
        }

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += 1LL * nums[i] * left[i] * right[i];
        }

        return sum;
    }


    long long sumOfMin(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (st.empty())
                left[i] = i + 1;
            else
                left[i] = i - st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Smaller or Equal Element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if (st.empty())
                right[i] = n - i;
            else
                right[i] = st.top() - i;

            st.push(i);
        }

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += 1LL * nums[i] * left[i] * right[i];
        }

        return sum;
    }


    long long subArrayRanges(vector<int>& nums) {

        long long maximumSum = sumOfMax(nums);
        long long minimumSum = sumOfMin(nums);

        return maximumSum - minimumSum;
    }
};