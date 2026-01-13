class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0;
        double sum = 0;

        // first window
        for(int r = 0; r < k; r++){
            sum += nums[r];
        }

        double maxavg = sum / k;

        // sliding window
        for(int r = k; r < nums.size(); r++){
            sum = sum + nums[r] - nums[l];   
            double avg = sum / k;
            maxavg = max(maxavg, avg);
            l++;
        }

        return maxavg;
    }
};
