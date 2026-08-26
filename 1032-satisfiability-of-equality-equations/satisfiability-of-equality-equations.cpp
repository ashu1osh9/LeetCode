class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int u){

        if(u == parent[u]) return u ;

        return find(parent[u]);
    }

// rank 
    void Union (int u , int v){
        int u_parent = find(u);
        int v_parent = find(v);

        if(rank[u_parent] == rank[v_parent]){

            parent[v_parent] = u_parent;
            rank[u_parent]++;


        }

        if(rank[u_parent]>rank[v_parent]){
            parent[v_parent] = u_parent;
        }
        if(rank[u_parent]<rank[v_parent]){
            parent[u_parent] = v_parent;
        }

        
    }
    bool equationsPossible(vector<string>& equations) {

        parent.assign(26,0);
          rank.assign(26, 0);


        for(int i = 0;i<26;i++){
            parent[i] = i;
        }

        // now union the all node which are same 

        for(auto &c : equations){


            if(c[1]== '='){

                int x = c[0] -'a';
                int y = c[3] - 'a';

                Union(x, y);
            }
        }

        // find all belong to same group aur not -- if same group then cycle 

        for(auto &s : equations){

            if(s[1]== '!'){

                int x = s[0] -'a';
                int y = s[3] -'a';
                int x_parent = find(x);
                int y_parent = find(y);

                if(x_parent == y_parent) return false;
            }
        }

return true;






        
    }
};         