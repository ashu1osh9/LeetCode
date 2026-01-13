class Solution {
public:
    int maxVowels(string s, int k) {
        int l = 0;
        int lens = 0;
        int maxi = 0;
        for(int r = 0;r<k;r++){
            if(s[r]=='a'||s[r]=='e'||s[r]=='i'||s[r]=='o'||s[r]=='u')
            lens++;
        }
        maxi = lens;
        for(int r = k;r<s.size();r++){
            if(s[l]=='a'||s[l]=='e'||s[l]=='i'||s[l]=='o'||s[l]=='u'){
                lens--;
            }
            l++;

            if(s[r]=='a'||s[r]=='e'||s[r]=='i'||s[r]=='o'||s[r]=='u'){
                lens++;
            }
            maxi = max(maxi,lens);
            
        }

        return maxi;

        
    }
};