class Solution {
public:
    vector<int> solve(int n) {

        vector<int> ans;

        for (int i = 0; i <= n; i++) {

            if (i == 0) {
                ans.push_back(0);
                continue;
            }

            string binary = "";
            int count = 0;
            int j = i;

            while (j > 0) {
                int rem = j % 2;
                binary.push_back(rem + '0');
                j = j / 2;
            }

            for (int k = 0; k < binary.size(); k++) {
                if (binary[k] == '1')
                    count++;
            }

            ans.push_back(count);
        }

        return ans;
    }

    vector<int> countBits(int n) {
        return solve(n);
    }
};