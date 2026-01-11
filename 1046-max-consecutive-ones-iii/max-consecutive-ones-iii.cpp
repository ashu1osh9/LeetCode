class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;   // left pointer
        int z = 0;   // zero count in window
        int ans = 0; // maximum length

        for (int r = 0; r < nums.size(); r++) {

            if (nums[r] == 0)
                z++; // count zero

            while (z > k) { // shrink window if zeros exceed k
                if (nums[l] == 0)
                    z--;
                l++;
            }

            ans = max(ans, r - l + 1); // update answer
        }

        return ans;
    }
};
