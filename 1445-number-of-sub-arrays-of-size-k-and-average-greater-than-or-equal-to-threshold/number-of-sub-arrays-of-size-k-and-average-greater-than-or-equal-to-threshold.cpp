class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0;
        int sum = 0;
        int cnt = 0;

        for(int r = 0; r < k; r++){
            sum += arr[r];
        }

        if(sum / k >= threshold)
            cnt++;

        for(int r = k; r < arr.size(); r++){
            sum = sum + arr[r] - arr[l]; 
            l++;

            if(sum / k >= threshold)
                cnt++;
        }

        return cnt;
    }
};
