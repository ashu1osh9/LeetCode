class Solution {
public:
     
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        int i = 0;
        int j = 0;
        pair<int,int> prev = {0,0};

     for(i = 0, j = 0; i >= 0 && i < n && j >= 0 && j < m;){

        if(visited[i][j] == 1) break;
         
        visited[i][j] = 1;
        prev.first = i;
        prev.second = j;


        if(grid[i][j] == 'L'){
           
            i = i;
            j = j-1;


        }else if(grid[i][j]=='R'){
           
            i = i ;
            j = j +1;

        }else if(grid[i][j]=='U'){
            visited[i][j]=1;
            prev.first = i;
            prev.second = j;
            i = i-1;
            j = j ;
        }else{
           
            i = i +1;
            j = j ;

        }


        
      }

      return {prev.first,prev.second};



    }
        
    
};