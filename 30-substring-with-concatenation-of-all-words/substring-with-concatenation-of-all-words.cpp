class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int n = s.size();
        int wordLen = words[0].size();
        int totalWords = words.size();
        int windowLen = wordLen * totalWords;

        unordered_map<string,int> target;

        for(auto &w : words){
            target[w]++;
        }

        // offsets
        for(int i = 0; i < wordLen; i++){

            int left = i;
            int count = 0;

            unordered_map<string,int> window;

            // move right in chunks
            for(int right = i; right + wordLen <= n; right += wordLen){

                string word = s.substr(right, wordLen);

                // valid word
                if(target.find(word) != target.end()){

                    window[word]++;
                    count++;

                    // extra frequency
                    while(window[word] > target[word]){

                        string leftWord = s.substr(left, wordLen);

                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // valid window
                    if(count == totalWords){

                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLen);

                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                }

                // invalid word
                else{

                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return ans;
    }
};