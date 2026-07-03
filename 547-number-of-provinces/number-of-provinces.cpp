class Solution {
public:
    void dfs(int node , vector<vector<int>>&adjList,vector<int>&visited){
        visited[node] = 1;
        for(auto it : adjList[node]){
            if(!visited[it]){
                dfs(it,adjList,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<vector<int>>adjList(n);
        // adjacency matrix to adjacency list
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(isConnected[i][j]==1 && i !=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                    
                }
            }
        }
        int cnt = 0; // count
        vector<int>visited(n,0);
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,adjList,visited);
            }
        }

      return cnt;

        
    }
};