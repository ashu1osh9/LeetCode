class Solution {
public:
    vector<string> createGrid(int m, int n) {

        vector<vector<char>>grid(m,vector<char>(n,'#'));
        vector<string>ans;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0 || j == n-1){
                    grid[i][j] = '.';
                }
            }
        }
        for(int i = 0;i<m;i++){
             string temp = "";
            for(int j = 0; j < n; j++){
                temp += grid[i][j];
            }
            ans.push_back(temp);
        }

        return ans;


        
    }
};