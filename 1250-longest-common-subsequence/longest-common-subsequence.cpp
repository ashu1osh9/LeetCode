// class Solution {
// public:
        


// // recursion -- 0 to n  

//     int solve(string str1, string str2,int i , int j ){

//         if(i>=str1.size()|| j >= str2.size()){
//             return 0;
//         }
//         if(str1[i]==str2[j]){
//             return 1 + solve(str1,str2,i+1, j+1);
//         }
//         else{
//             return max(solve(str1,str2,i+1,j),solve(str1,str2,i,j+1));
//         }

//     }
    
//      int longestCommonSubsequence(string text1, string text2) {

//         return solve(text1,text2,0,0);

//     }
// };

// dp memoization 
class Solution {
public:
        
    vector<vector<int>>dp;

    int solve(string &str1, string &str2,int i , int j ){

        if(i>=str1.size()|| j >= str2.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(str1[i]==str2[j]){
            return dp[i][j] = 1 + solve(str1,str2,i+1, j+1);
        }
        else{
            return dp[i][j] = max(solve(str1,str2,i+1,j),solve(str1,str2,i,j+1));
        }

    

    }
    
     int longestCommonSubsequence(string text1, string text2) {
        dp.clear();
        dp.assign(text1.size(),vector<int>(text2.size(),-1));

        return solve(text1,text2,0,0);

    }
};

