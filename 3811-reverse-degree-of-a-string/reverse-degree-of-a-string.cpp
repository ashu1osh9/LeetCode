class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char,int>map;
        int cnt = 26;

        for(char ch = 'a'; ch <= 'z'; ch++) {


            map[ch] = cnt;
            cnt--;
    
}
int sum = 0;

          for(int i = 0; i < s.size(); i++) {
            int val = map[s[i]];
            sum += val * (i + 1);
        }
        return sum;
        
    }
};