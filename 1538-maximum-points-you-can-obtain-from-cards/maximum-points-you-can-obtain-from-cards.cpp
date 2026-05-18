class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int r = cardPoints.size();
        int sum = 0;
        for(int i = 0 ;i<k;i++){
            sum +=cardPoints[i];
        }
        int maxi = sum;
        int end = r - 1;
        for(int j = k - 1;j>=0;j--){
            sum -=cardPoints[j];
            sum +=cardPoints[end];
            end --;
            maxi = max(maxi,sum);
        }
        return maxi;
        
    }
};