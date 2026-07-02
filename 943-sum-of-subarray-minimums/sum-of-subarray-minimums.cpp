class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(n), next(n);
        stack<int> st;

        // Previous Smaller (strictly smaller)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            if (st.empty())
                prev[i] = -1;
            else
                prev[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Smaller or Equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if (st.empty())
                next[i] = n;
            else
                next[i] = st.top();

            st.push(i);
        }

        long long ans = 0;
        long long mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;

            ans = (ans + (arr[i] * left % mod) * right) % mod;
        }

        return ans;
    }
};
