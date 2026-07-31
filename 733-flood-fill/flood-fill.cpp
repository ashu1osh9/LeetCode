//T.C => O(N)
class Solution {
public:
    typedef pair<int,int>P;
    vector<vector<int>>direction = {{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<P>q;
        int n = image.size();
        int m = image[0].size();
        int original = image[sr][sc];
        q.push({sr,sc});
        image[sr][sc] = color;
        if(original==color){
            return image;
        }
        // T.C : m*n;
        while(!q.empty()){
            int N = q.size();
            while(N--){
                P curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                for(vector<int>&dir:direction){
                    int new_i = i + dir[0];
                    int new_j= j + dir[1];
                    if(new_i >=0 && new_i <n && new_j >=0 && new_j <m && image[new_i][new_j]== original){
                        image[new_i][new_j] = color;
                        q.push({new_i,new_j});

                    }
                    
                }

            }
        }
            return image;

        
    }
};