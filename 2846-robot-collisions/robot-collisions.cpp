class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[positions[i]]=i;
        }
        stack<int>st;
        sort(positions.begin(),positions.end());
        for(int i=0;i<n;i++){
              int x=mp[positions[i]]; // x is the index
              while(!st.empty() && directions[st.top()]=='R' && (directions[x]=='L')){
                       
                     
                          if(healths[st.top()]==healths[x]){
                            healths[st.top()]=0;
                            healths[x]=0;
                            st.pop();
                            break;
                          }
                          else if(healths[st.top()]>healths[x]){
                            healths[x]=0;
                            healths[st.top()]--;
                               break;
                          }
                          else{
                            healths[st.top()]=0;
                            st.pop();
                            healths[x]--;
                           
                          }
                      
                   
              }
            if(healths[x]>0){
                st.push(x);

            }
        }
vector<int>result;
        for(int i=0;i<n;i++){
               if(healths[i]>0){
  result.push_back(healths[i]);
               }
             
          
        }
        return result;
    }
};