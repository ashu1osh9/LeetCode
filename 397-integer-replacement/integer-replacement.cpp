class Solution {
public:
    int solve(long long n){
        if(n == 1) return 0;
     
        
        
         if(n % 2 == 0) {
            return 1 + solve(n/2);

         }
         else{

             int odd_inc = 1+ solve(n+1);
            int  odd_des = 1 + solve(n-1);
            return min(odd_inc,odd_des);




         }
         
         
         }
         
    
    int integerReplacement(int n) {
        return solve(n);
        
    }
};