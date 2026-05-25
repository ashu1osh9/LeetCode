// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         // with two pointer method
//         int n=nums.size();
//         int i=0;
//         int j=0;
//         int res=0;
//         int sum=0;
//         while(j<n){
//              sum+=nums[j];
//             // if(j==n-1){
//             //     j=i;
//             //     i++;
//             //     sum=0;
//             // }
         
//           if(sum>k){
//             // sum-=nums[i];
//             sum=0;
//            j=i;
//             i++;
            
//           }
//           else if(sum==k){
//             res++;
//           }
//           j++;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // brute force
        int n=nums.size();
        int i=0;
        int j=0;
        int res=0;
        int sum=0;
       for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
             sum+=nums[j];
             if(sum==k){
               res++;
             }
        }
       }
        return res;
    }
};