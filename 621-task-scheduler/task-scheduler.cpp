class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> freq(26,0);
        
        for(char c:tasks)
            freq[c-'A']++;
        
        int maxFreq=*max_element(freq.begin(),freq.end());
        
        int maxCount=0;
        
        for(int x:freq)
            if(x==maxFreq)
                maxCount++;
        
        int ans=(maxFreq-1)*(n+1)+maxCount;
        
        return max(ans,(int)tasks.size());
    }
};