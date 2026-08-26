class Solution {
public:
    int minimumPushes(string word) {

        map<char, int> mp;

        // word ke unique characters
        for(char ch : word) {
            mp[ch] = 0;
        }

        int cost = 1;
        int cnt = 0;
        int ans = 0;

        for(auto &it : mp) {

            it.second = cost;
            ans += cost;

            cnt++;

            if(cnt == 8) {
                cnt = 0;
                cost++;
            }
        }

        return ans;
    }
};