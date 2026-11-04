class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;

        for(int x = 1; x <= 26; x++) {
            vector<int> mp(26, 0);

            int i = 0, cnt = 0, good = 0;

            for(int j = 0; j < n; j++) {
                int c = s[j] - 'a';

                if(mp[c] == 0) cnt++;

                mp[c]++;

                if(mp[c] == k) good++;

                while(cnt > x) {
                    int c = s[i] - 'a';

                    if(mp[c] == k) good--;

                    mp[c]--;

                    if(mp[c] == 0) cnt--;

                    i++;
                }

                if(cnt == x && good == x) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
