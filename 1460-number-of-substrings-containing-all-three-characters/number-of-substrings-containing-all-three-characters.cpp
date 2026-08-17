class Solution {
public:
    int numberOfSubstrings(string s) {

        vector<int> cnt(3, 0);

        int l = 0;
        int result = 0;
        int n = s.size();

        for(int r = 0; r < n; r++) {

            // Right character ko window me add karo
            cnt[s[r] - 'a']++;

            // Jab window me a, b, c teeno aa jaye
            while(cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {

                // Current window valid hai
                result += n - r;

                // Left character ko window se remove karo
                cnt[s[l] - 'a']--;

                // Left pointer aage badhao
                l++;
            }
        }

        return result;
    }
};