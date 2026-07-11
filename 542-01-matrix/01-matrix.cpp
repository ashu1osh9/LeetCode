// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int n = mat.size();
//         int m = mat[0].size();
//         queue<pair<int,int>>que;
//         vector<int>vis(n,vector<int>(m,0));
//          vector<int>ans(n,vector<int>(m,0));
//         for(int i = 0;i<n<i++){
//             for(int j = 0;j<m;j++){
//                 if(mat[i][j]==0){
//                     que.push({i,j});
//                     ans[i][j] = 0;

//                 }
//             }
//         }
//     int count = 0;
//         while(!que.empty()){
//             count ++;
//             int sz = que.size();
//             while(sz--){

//                 int val = que.front();
//                 que.pop();
//                 int i = val.front;
//                 int j = val.second;
//                 visited[i][j] = 1;

//                 for(vector<int>dir:direction){
//                     int r = i + dir[0];
//                     int c = j + dir[1];
//                     if(mat[r][j]==1){
//                         que.push({r,c});
//                         ans[r][c] = count;

//                     }


//                 }


//             }

//         }
//         return ans;
        
//     }
// };

class Solution {
public:

    vector<vector<int>> direction = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        queue<pair<pair<int,int>,int>> que;

        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> ans(n, vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(mat[i][j]==0){

                    que.push({{i,j},0});
                    vis[i][j]=1;
                    ans[i][j]=0;
                }
            }
        }

        while(!que.empty()){

            auto val = que.front();
            que.pop();

            int i = val.first.first;
            int j = val.first.second;
            int step = val.second;

            for(auto dir : direction){

                int r = i + dir[0];
                int c = j + dir[1];

                if(r>=0 && r<n &&
                   c>=0 && c<m &&
                   !vis[r][c]){

                    vis[r][c]=1;
                    ans[r][c]=step+1;

                    que.push({{r,c},step+1});
                }
            }
        }

        return ans;
    }
};