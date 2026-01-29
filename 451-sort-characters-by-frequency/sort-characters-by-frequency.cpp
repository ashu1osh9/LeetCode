class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>un;
        for(int i = 0;i<s.size();i++){
            un[s[i]]++;
        }
        vector<string>bucket(s.size()+1); // bucket method 
        for(auto &it : un){
            bucket[it.second].append(it.second,it.first);
        }
        string r ="";
        for(int i = s.size();i>=1;i--){
            r += bucket[i];
        }
        return r;
    }
};