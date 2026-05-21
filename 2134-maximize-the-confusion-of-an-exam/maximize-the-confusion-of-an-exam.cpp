class Solution {
public:

    int solve(string &s, int k, char ch) {

        int left = 0;
        int cnt = 0;
        int ans = 0;

        for(int right = 0; right < s.size(); right++) {

            if(s[right] == ch)
                cnt++;

            while(cnt > k) {

                if(s[left] == ch)
                    cnt--;

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {

        return max(
            solve(answerKey, k, 'F'),
            solve(answerKey, k, 'T')
        );
    }
};