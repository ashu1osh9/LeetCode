class Solution {
public:
        vector<vector<int>>direction = {{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(int i , int j ,vector<vector<int>>&vis,vector<vector<char>>& board ){
        vis[i][j] = 1;
        int n = board.size();
        int m = board[0].size();

        for(auto dir : direction){
            int new_i = dir[0] + i;
            int new_j = dir[1] + j ;

            if(new_i >= 0 && new_i<n && new_j>=0 && new_j < m && board[new_i][new_j] == 'X' && vis[new_i][new_j]==0){
                dfs(new_i,new_j,vis,board);
            }
        }


    }
    int countBattleships(vector<vector<char>>& board) {

       queue<pair<int,int>> qu; // i and j store ;

        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j]=='X'){
                qu.push({i,j});
            }
            }
        }
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size()));
        int count = 0;

        while(!qu.empty()){

            auto index = qu.front();
            qu.pop();
            int i = index.first;
            int j = index.second;
            if(vis[i][j] != 1){
                count++;
                dfs(i,j,vis,board);

            }

            

        }
        return count;
        
    }
};